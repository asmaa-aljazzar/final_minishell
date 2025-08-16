/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:41:43 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 16:51:19 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin2(t_minishell *shell, int builtin_type)
{
	if (builtin_type == 4)
	{
		export_builtin(shell);
		return (1);
	}
	else if (builtin_type == 5)
	{
		unset_builtin(shell);
		return (1);
	}
	else if (builtin_type == 6)
	{
		env_builtin(shell);
		return (1);
	}
	else if (builtin_type == 7)
	{
		exit_builtin(shell);
		return (1);
	}
	return (0);
}

int	exec_builtin(t_minishell *shell)
{
	int	builtin_type;

	builtin_type = is_builtin(shell->cmd);
	if (builtin_type == 1)
	{
		echo_builtin(shell);
		return (1);
	}
	else if (builtin_type == 2)
	{
		cd_builtin(shell);
		return (1);
	}
	else if (builtin_type == 3)
	{
		pwd_builtin(shell);
		return (1);
	}
	else
		return (exec_builtin2(shell, builtin_type));
	return (0);
}
