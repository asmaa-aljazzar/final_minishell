/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_outputPipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:03:12 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:03:12 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	if_output_pipe(t_token *token, t_command **cmd, int *argc)
{
	if (token->type == PIPE)
	{
		if (*cmd && (*cmd)->argv)
			(*cmd)->argv[*argc] = NULL;
		if (*cmd)
			*cmd = (*cmd)->next;
		*argc = 0;
	}
}
