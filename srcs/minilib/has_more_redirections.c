/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_more_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 13:04:21 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 13:04:21 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_more_redirections(t_token **tokens, int start_index, t_type t1,
		t_type t2)
{
	int	i;

	i = start_index;
	while (tokens[i])
	{
		if (tokens[i]->type == t1 || tokens[i]->type == t2)
			return (1);
		i++;
	}
	return (0);
}
