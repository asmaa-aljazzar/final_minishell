/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 11:13:03 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 11:13:03 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_pipe(t_minishell *ms)
{
	t_token	**curr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	curr = ms->tok;
	while (curr[i])
	{
		if (curr[i]->type == PIPE)
			count++;
		i++;
	}
	ms->pipe_count = count;
}
