/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_double_quoted_token.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:22:36 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:22:58 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_double_quoted_token(t_token *token, char *expanded,
		t_token **new_tokens, int *new_count, int did_expand)
{
	free(token->word);
	token->word = expanded;
	token->expanded = did_expand;
	new_tokens[(*new_count)++] = token;
}
