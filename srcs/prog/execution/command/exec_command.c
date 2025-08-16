/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:41:52 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 16:44:39 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_command_empty_all(t_command *cmd)
{
	char	*arg;
	int		i;

	i = 0;
	if (!cmd || !cmd->argv)
		return (1);
	while (cmd->argv[i])
	{
		arg = cmd->argv[i];
		while (*arg && (*arg == ' ' || *arg == '\t' || *arg == '\n'))
			arg++;
		if (*arg != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	exec_command(t_minishell *ms)
{
	t_command	*cmd;
	int			redir_status;

	cmd = ms->cmd;
	if (!cmd || !cmd->argv)
	{
		ms->exit_code = 127;
		return (-1);
	}
	if (!cmd->argv[0])
	{
		ms->exit_code = 0;
		return (0);
	}
	if (cmd->argv[0][0] == '\0')
	{
		if (cmd->argv_expanded && cmd->argv_expanded[0] == 0)
		{
			ft_putstr_fd("minishell: : command not found\n", STDERR_FILENO);
			ms->exit_code = 127;
			return (-1);
		}
		else
		{
			ms->exit_code = 0;
			return (0);
		}
	}
	if (is_command_empty_all(cmd))
	{
		ms->exit_code = 0;
		return (0);
	}
	redir_status = 0;
	if (redir_status != 0)
	{
		if (redir_status > 0)
			return (0);
		return (-1);
	}
	if (!ms->envp)
	{
		ms->exit_code = 1;
		return (-1);
	}
	if (is_builtin(cmd))
	{
		compare_commands(ms);
		return (0);
	}
	return (-1);
}
