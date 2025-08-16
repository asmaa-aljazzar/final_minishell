/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:15:09 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:15:09 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*init_env(t_minishell *minishell, char **environ)
{
	int		i;
	t_env	*head;
	t_env	*tail;
	t_env	*new_node;

	head = NULL;
	tail = NULL;
	i = 0;
	while (environ[i])
	{
		new_node = create_env_node(minishell, environ[i]);
		if (!new_node)
			return (NULL);
		append_env_node(new_node, &head, &tail);
		i++;
	}
	return (head);
}
