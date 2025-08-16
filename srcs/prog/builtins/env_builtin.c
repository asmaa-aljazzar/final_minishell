/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:58:17 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 16:28:03 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_builtin_print_env(t_minishell *minishell)
{
	t_env	*curr;

	curr = minishell->env;
	while (curr)
	{
		if (curr->value)
			printf("%s=%s\n", curr->name, curr->value);
		curr = curr->next;
	}
	minishell->exit_code = 0;
}

char	*env_builtin_resolve_path(t_minishell *minishell, t_command *cmd)
{
	char				*path;
	int					is_direct_path;
	static t_command	temp_cmd = {0};
	t_command			*original_cmd;

	path = NULL;
	is_direct_path = (ft_strchr(cmd->argv[1], '/') != NULL);
	if (!is_direct_path)
	{
		temp_cmd.argv = &cmd->argv[1];
		original_cmd = minishell->cmd;
		minishell->cmd = &temp_cmd;
		path = get_path(minishell, cmd->argv);
		minishell->cmd = original_cmd;
		if (!path)
		{
			ft_putstr_fd("minishell: env: ", STDERR_FILENO);
			ft_putstr_fd(cmd->argv[1], STDERR_FILENO);
			ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
			minishell->exit_code = 127;
		}
	}
	return (path);
}

void	env_builtin_execute_child(t_minishell *minishell, t_command *cmd,
		char *path)
{
	int	is_direct_path;

	setup_signals_child();
	is_direct_path = (ft_strchr(cmd->argv[1], '/') != NULL);
	if (is_direct_path)
		execve(cmd->argv[1], &cmd->argv[1], minishell->envp);
	else
		execve(path, &cmd->argv[1], minishell->envp);
	ft_putstr_fd("minishell: env: ", STDERR_FILENO);
	ft_putstr_fd(cmd->argv[1], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (errno == EISDIR)
		ft_putstr_fd("Not a directory\n", STDERR_FILENO);
	else if (errno == ENOENT)
		ft_putstr_fd("No such file or directory\n", STDERR_FILENO);
	else if (errno == EACCES)
		ft_putstr_fd("Permission denied\n", STDERR_FILENO);
	else
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	if (errno == EACCES || errno == EISDIR)
		exit(127);
	exit(126);
}

void	env_builtin_wait_child(t_minishell *minishell, pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		minishell->exit_code = WEXITSTATUS(status);
	else
		minishell->exit_code = 1;
}

void	env_builtin(t_minishell *minishell)
{
	pid_t	pid;
	char	*path;

	if (minishell->cmd->argv[1] == NULL)
	{
		env_builtin_print_env(minishell);
		return ;
	}
	path = env_builtin_resolve_path(minishell, minishell->cmd);
	if (!path && minishell->exit_code == 127)
		return ;
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("minishell: env: fork failed\n", STDERR_FILENO);
		free(path);
		minishell->exit_code = 1;
		return ;
	}
	if (pid == 0)
		env_builtin_execute_child(minishell, minishell->cmd, path);
	else
		env_builtin_wait_child(minishell, pid);
	free(path);
}
