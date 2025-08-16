/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_max_tokens_after_expansion.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 13:05:00 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 13:05:00 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_max_tokens_after_expansion(t_minishell *ms)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (ms->tok && ms->tok[i])
	{
		if (ms->tok[i]->qtype == QUOTE_SINGLE)
			max += 1;
		else
			max += 20;
		i++;
	}
	if (max > 0)
		return (max);
	else
		return (100);
}
