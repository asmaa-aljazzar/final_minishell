/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_first_split_token.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:23:00 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:26:46 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_first_split_token(t_token *token, const char *word,
		int did_expand, t_token **new_tokens, int *new_count)
{
	free(token->word);
	token->word = ft_strdup(word);
	if (!token->word)
		return ;
	token->qtype = QUOTE_NONE;
	token->expanded = did_expand;
	new_tokens[(*new_count)++] = token;
}
