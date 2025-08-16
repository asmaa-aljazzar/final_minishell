/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:01:51 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:01:51 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*create_command_list(t_minishell *ms, int count)
{
	t_command	*head;
	t_command	*curr;
	t_command	*new;
	int			i;

	head = NULL;
	curr = NULL;
	i = 0;
	while (i < count + 1)
	{
		new = init_command(ms);
		if (!head)
		{
			head = new;
			curr = new;
		}
		else
		{
			curr->next = new;
			curr = new;
		}
		i++;
	}
	return (head);
}
