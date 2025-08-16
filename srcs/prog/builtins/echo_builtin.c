/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:55:26 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 16:05:49 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_n_flag(char *str)
{
	int	i;

	i = 0;
	if (str[i++] != '-')
		return (0);
	if (str[i] != 'n')
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	echo_builtin(t_minishell *shell)
{
	t_command	*cmd;
	int			i;
	int			newline;

	cmd = shell->cmd;
	i = 1;
	newline = 1;
	while (cmd->argv[i] && is_valid_n_flag(cmd->argv[i]))
	{
		newline = 0;
		i++;
	}
	while (cmd->argv[i])
	{
		ft_putstr_fd(cmd->argv[i], STDOUT_FILENO);
		if (cmd->argv[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (newline)
		ft_putstr_fd("\n", STDOUT_FILENO);
	shell->exit_code = 0;
}
