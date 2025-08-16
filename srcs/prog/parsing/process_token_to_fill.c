/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_token_to_fill.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:03:07 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:03:07 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_token_to_fill(t_minishell *ms, t_command **cmd, t_token *tok,
		int *arg_idx)
{
	if (tok->type == PIPE)
	{
		(*cmd)->argv[*arg_idx] = NULL;
		(*cmd)->argv_expanded[*arg_idx] = 0;
		*cmd = (*cmd)->next;
		*arg_idx = 0;
		return (1);
	}
	if (tok->type == T_INPUT || tok->type == T_HEREDOC || tok->type == T_OUTPUT
		|| tok->type == T_APPEND)
		return (2);
	else if (tok->type == T_WORD)
	{
		copy_token_to_argvs(ms, *cmd, tok, *arg_idx);
		(*arg_idx)++;
		return (0);
	}
	return (3);
}
