/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:23:10 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:23:11 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_env_var(t_minishell *shell, char *name, char *value)
{
	if (!name || !value)
		return (0);
	if (!update_existing_env_var(shell, name, value))
	{
		if (!create_new_env_var(shell, name, value))
			return (0);
	}
	else if (update_existing_env_var(shell, name, value) == -1)
		return (0);
	return (1);
}
