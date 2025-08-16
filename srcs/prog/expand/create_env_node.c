/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:22:30 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:25:28 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*create_env_node(t_minishell *ms, char *environ)
{
	char	*equal;
	t_env	*node;

	equal = ft_strchr(environ, '=');
	if (!equal)
		return (NULL);
	node = malloc(sizeof(t_env));
	if (!node)
		ft_exit(ms, "Memory allocation failed", 1);
	node->name = ft_substr(environ, 0, equal - environ);
	if (!node->name)
		return (NULL);
	node->value = ft_strdup(equal + 1);
	if (!node->value)
		return (NULL);
	node->next = NULL;
	return (node);
}
