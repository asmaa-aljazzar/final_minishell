/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_existing_env_var.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:23:12 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:23:37 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_existing_env_var(t_minishell *shell, char *name, char *value)
{
	t_env	*current;

	current = shell->env;
	while (current)
	{
		if (ft_strncmp(current->name, name, ft_strlen(name)) == 0)
		{
			free(current->value);
			current->value = ft_strdup(value);
			if (!current->value)
				return (-1);
			if (!update_envp_array(shell, name, value))
				return (-1);
			return (1);
		}
		current = current->next;
	}
	return (0);
}
