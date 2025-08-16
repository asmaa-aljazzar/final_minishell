/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_two_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:08:48 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:08:48 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	merge_two_tokens(t_minishell *minishell, t_token *dst, t_token *src)
{
	char	*joined_word;

	joined_word = ft_strjoin(dst->word, src->word);
	if (!joined_word)
		ft_exit(minishell, "malloc failed", 1);
	free(dst->word);
	dst->word = joined_word;
	free_token(src);
}
