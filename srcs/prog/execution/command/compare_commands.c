/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:41:40 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:11:25 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	compare_commands(t_minishell *shell)
{
	t_command	*cmd;

	cmd = shell->cmd;
	if (!cmd || !cmd->argv || !cmd->argv[0])
	{
		shell->exit_code = 0;
		return ;
	}
	if (ft_strcmp(cmd->argv[0], "echo") == 0)
		echo_builtin(shell);
	else if (ft_strcmp(cmd->argv[0], "cd") == 0)
		cd_builtin(shell);
	else if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		pwd_builtin(shell);
	else if (ft_strcmp(cmd->argv[0], "export") == 0)
		export_builtin(shell);
	else if (ft_strcmp(cmd->argv[0], "unset") == 0)
		unset_builtin(shell);
	else if (ft_strcmp(cmd->argv[0], "env") == 0)
		env_builtin(shell);
	else if (ft_strcmp(cmd->argv[0], "exit") == 0)
		exit_builtin(shell);
	else
		execute_external_command(shell, cmd->argv);
	ft_exit(shell, "Built-in command executed", shell->exit_code);
}
