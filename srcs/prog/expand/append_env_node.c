/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_env_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:20:14 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:20:15 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	append_env_node(t_env *new_node, t_env **head, t_env **tail)
{
	if (new_node)
	{
		if (!*head)
			*head = new_node;
		else
			(*tail)->next = new_node;
		*tail = new_node;
	}
}
