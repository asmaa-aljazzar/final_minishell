/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:08:52 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:08:52 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	merge_words(t_minishell *minishell)
{
	t_token	**orig;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!minishell || !minishell->tok)
		return ;
	orig = minishell->tok;
	while (orig[i])
	{
		minishell->tok[k] = orig[i];
		advance_and_merge(minishell, orig, &i, k);
		k++;
		i++;
	}
	minishell->tok[k] = NULL;
	minishell->tokens_count = k;
}
