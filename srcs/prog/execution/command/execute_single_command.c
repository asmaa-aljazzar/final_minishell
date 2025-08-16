/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:44:58 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 16:53:44 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_empty_command_with_output(t_minishell *ms)
{
	t_command	*cmd;

	cmd = ms->cmd;
	if (!cmd)
		return (0);
	if ((!cmd->argv || !cmd->argv[0] || is_command_empty(cmd))
		&& (cmd->redir))
	{
		if (main_redirection(ms) == -1)
			return (-1);
		ms->exit_code = 0;
		return (1);
	}
	return (0);
}

int	is_command_empty(t_command *cmd)
{
	char	*arg;

	if (!cmd || !cmd->argv || !cmd->argv[0])
		return (1);
	arg = cmd->argv[0];
	while (*arg && (*arg == ' ' || *arg == '\t' || *arg == '\n'))
		arg++;
	if (*arg == '\0')
	{
		if (cmd->argv_expanded
			&& cmd->argv_expanded[0])
			return (1);
		return (0);
	}
	return (0);
}

static int	save_and_apply_redirection(t_minishell *ms, int *saved_stdout)
{
	t_command	*cmd;

	cmd = ms->cmd;
	*saved_stdout = -1;
	if (cmd->redir)
	{
		*saved_stdout = dup(STDOUT_FILENO);
		if (*saved_stdout < 0)
		{
			perror("dup");
			ms->exit_code = 1;
			return (-1);
		}
		if (main_redirection(ms) != 0)
		{
			if (*saved_stdout >= 0)
				close(*saved_stdout);
			ms->exit_code = 1;
			return (-1);
		}
	}
	return (0);
}

static void	execute_builtin_and_restore(t_minishell *ms, int saved_stdout)
{
	compare_commands(ms);
	if (saved_stdout >= 0)
	{
		if (dup2(saved_stdout, STDOUT_FILENO) == -1)
			ft_exit(ms, "dup2 stdout failed", 1);
		close(saved_stdout);
	}
}

static int	handle_builtin_with_redirection(t_minishell *ms)
{
	int	saved_stdout;

	if (save_and_apply_redirection(ms, &saved_stdout) != 0)
	{
		free_simple_resources(ms);
		return (-1);
	}
	execute_builtin_and_restore(ms, saved_stdout);
	return (0);
}

static void	exec_child(t_minishell *ms)
{
	setup_signals_child();
	if (main_redirection(ms) != 0)
		ft_exit(ms, "main_redirection failed", 1);
	execute_external_command(ms, ms->cmd->argv);
	ft_exit(ms, "execute_external_command failed", 1);
}

static void	fork_and_execute_external(t_minishell *ms)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		ms->exit_code = 1;
		ft_exit(ms, "fork failed", 1);
	}
	else if (pid == 0)
		exec_child(ms);
	else
	{
		signal(SIGINT, handle_c);
		signal(SIGQUIT, handlequit);
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
			ms->exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			ms->exit_code = 128 + WTERMSIG(status);
	}
}

static int	validate_command_for_execution(t_minishell *ms)
{
	t_command	*cmd;

	cmd = ms->cmd;
	if (!cmd || !cmd->argv)
	{
		ms->exit_code = 0;
		free_simple_resources(ms);
		return (0);
	}
	if (is_command_empty(cmd))
	{
		ms->exit_code = 0;
		free_simple_resources(ms);
		return (0);
	}
	return (1);
}

static void	handle_builtin_command(t_minishell *ms)
{
	if (handle_builtin_with_redirection(ms) != 0)
		return ;
}

void	execute_single_command(t_minishell *ms)
{
	if (!validate_command_for_execution(ms))
		return ;
	if (ms->cmd && is_builtin(ms->cmd))
	{
		handle_builtin_command(ms);
		return ;
	}
	fork_and_execute_external(ms);
}
