/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 13:04:16 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 13:04:16 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_command *cmd)
{
	if (!cmd || !cmd->argv || !cmd->argv[0])
		return (0);
	if (ft_strcmp(cmd->argv[0], "echo") == 0)
		return (1);
	if (ft_strcmp(cmd->argv[0], "cd") == 0)
		return (2);
	if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		return (3);
	if (ft_strcmp(cmd->argv[0], "export") == 0)
		return (4);
	if (ft_strcmp(cmd->argv[0], "unset") == 0)
		return (5);
	if (ft_strcmp(cmd->argv[0], "env") == 0)
		return (6);
	if (ft_strcmp(cmd->argv[0], "exit") == 0)
		return (7);
	return (0);
}
