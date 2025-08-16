/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_argvs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:02:14 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:02:14 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fill_argvs(t_minishell *ms)
{
	t_command	*cmd;
	int			i;
	int			arg_idx;
	t_token		*tok;

	cmd = ms->cmd;
	i = 0;
	arg_idx = 0;
	while (ms->tok[i])
	{
		tok = ms->tok[i];
		if (process_token_to_fill(ms, &cmd, tok, &arg_idx) == 2)
		{
			i++;
			if (ms->tok[i])
				ms->tok[i]->type = T_FILE;
			else
			{
				ft_printf("syntax error near unexpected token `newline'\n");
				ms->exit_code = 2;
				return (-1);
			}
		}
		i++;
	}
	if (cmd)
		cmd->argv[arg_idx] = NULL;
	return (0);
}
