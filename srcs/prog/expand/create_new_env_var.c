/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_env_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:22:34 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:25:45 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_new_env_var(t_minishell *shell, char *name, char *value)
{
	t_env	*current;
	t_env	*new_var;

	new_var = malloc(sizeof(t_env));
	if (!new_var)
	{
		ft_putstr_fd("minishell: malloc failed\n", STDERR_FILENO);
		return (0);
	}
	new_var->name = ft_strdup(name);
	if (!new_var->name)
		return (0);
	new_var->value = ft_strdup(value);
	if (!new_var->value)
	{
		free(new_var->name);
		return (0);
	}
	new_var->next = NULL;
	if (!shell->env)
		shell->env = new_var;
	else
	{
		current = shell->env;
		while (current->next)
			current = current->next;
		current->next = new_var;
	}
	if (!update_envp_array(shell, name, value))
		return (0);
	return (1);
}
