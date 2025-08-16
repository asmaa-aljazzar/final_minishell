/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_quoted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:09:39 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:09:39 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tokenize_quoted(t_minishell *ms, int *k, int *i, int glued)
{
	char	quote;
	char	*word;

	quote = ms->input[*i];
	if (quote == '\'')
		ms->in_single_quote = 1;
	else if (quote == '"')
		ms->in_double_quote = 1;
	word = read_quoted_content(ms, i, quote);
	if (!word)
		return (0);
	create_quoted_token(ms, k, word, quote, glued);
	(*i)++;
	if (quote == '\'')
		ms->in_single_quote = 0;
	else if (quote == '"')
		ms->in_double_quote = 0;
	ms->last_token_end = *i - 1;
	return (1);
}
