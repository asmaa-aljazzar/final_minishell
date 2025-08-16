/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_and_merge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:08:03 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:08:03 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	advance_and_merge(t_minishell *minishell, t_token **orig, int *i, int k)
{
	while (orig[*i + 1] && minishell->tok[k]->type == T_WORD && orig[*i
		+ 1]->type == T_WORD && orig[*i + 1]->glued == 1)
	{
		merge_two_tokens(minishell, minishell->tok[k], orig[*i + 1]);
		(*i)++;
	}
}
