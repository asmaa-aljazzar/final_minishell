/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:01:46 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:01:46 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	allocate_argv(t_minishell *minishell, int *argc, t_command **cmd,
		int *i)
{
	t_token	*token;

	token = minishell->tok[*i];
	if (token->type == PIPE)
	{
		if (*argc > 0)
		{
			(*cmd)->argv = malloc(sizeof(char *) * ((*argc) + 1));
			(*cmd)->argv_expanded = malloc(sizeof(int) * ((*argc) + 1));
			if (!(*cmd)->argv || !(*cmd)->argv_expanded)
				ft_exit(minishell, "malloc failed", EXIT_FAILURE);
			(*cmd)->argv[*argc] = NULL;
		}
		*argc = 0;
		*cmd = (*cmd)->next;
	}
	else if (token->type != T_INPUT && token->type != T_HEREDOC
		&& token->type != T_OUTPUT && token->type != T_APPEND)
	{
		(*argc)++;
	}
}
