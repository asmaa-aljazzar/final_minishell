/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_glued.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 11:25:01 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 11:25:01 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_glued(t_minishell *ms, int *i, int token_index)
{
	int	glued;
	int	start;
	int	j;

	start = *i;
	glued = 1;
	if (token_index == 0)
	{
		ms->last_token_end = *i;
		return (0);
	}
	j = ms->last_token_end + 1;
	while (j < start)
	{
		if (ms->input[j] == ' ' || ms->input[j] == '\t')
		{
			glued = 0;
			break ;
		}
		j++;
	}
	return (glued);
}
