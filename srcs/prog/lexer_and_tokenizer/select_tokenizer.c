/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_tokenizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:09:13 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:09:13 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	select_tokenizer(t_minishell *ms, int *k, int *i, int glued)
{
	char	c;

	c = ms->input[*i];
	if (c == '|' && !ms->in_single_quote && !ms->in_double_quote)
		tokenize_pipe_op(ms, k, i);
	else if (c == '<' && !ms->in_single_quote && !ms->in_double_quote)
		tokenize_input_redir(ms, k, i);
	else if (c == '>' && !ms->in_single_quote && !ms->in_double_quote)
		tokenize_output_redir(ms, k, i);
	else if ((c == '\'' && !ms->in_double_quote) || (c == '"'
			&& !ms->in_single_quote))
	{
		if (!tokenize_quoted(ms, k, i, glued))
			return (0);
	}
	else
		tokenize_normal_string(ms, k, i, glued);
	return (1);
}
