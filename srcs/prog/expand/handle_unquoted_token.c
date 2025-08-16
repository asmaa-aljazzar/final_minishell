/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unquoted_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:23:03 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:29:32 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_unquoted_token(t_minishell *ms, t_token *token, char *expanded,
		t_token **new_tokens, int *new_count, int did_expand)
{
	char	**split_words;
	int		j;

	split_words = split_on_whitespace(expanded);
	if (!split_words || !split_words[0])
	{
		free(token->word);
		token->word = ft_strdup("");
		token->expanded = did_expand;
		new_tokens[(*new_count)++] = token;
	}
	else
	{
		j = 0;
		while (split_words[j])
		{
			if (j == 0)
				handle_first_split_token(token, split_words[j], did_expand,
					new_tokens, new_count);
			else
				new_tokens[(*new_count)++] = create_new_token(ms,
						split_words[j],
						did_expand);
			j++;
		}
	}
	free_split_array(split_words);
	free(expanded);
}
