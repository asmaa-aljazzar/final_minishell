/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_for_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:02:05 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:02:05 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	argv_for_commands(t_minishell *minishell)
{
	t_command	*cmd;
	int			i;
	int			argc;

	cmd = minishell->cmd;
	i = 0;
	argc = 0;
	while (minishell->tok[i])
	{
		allocate_argv(minishell, &argc, &cmd, &i);
		i++;
	}
	if (cmd && argc > 0)
	{
		cmd->argv = malloc(sizeof(char *) * (argc + 1));
		cmd->argv_expanded = malloc(sizeof(int) * (argc + 1));
		if (!cmd->argv || !cmd->argv_expanded)
			ft_exit(minishell, "malloc failed", EXIT_FAILURE);
		cmd->argv[argc] = NULL;
	}
}
