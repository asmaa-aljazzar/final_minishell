/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_existing_envp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:23:06 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:30:47 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	replace_existing_envp(t_minishell *shell, char *name, char *new_entry)
{
	int	i;

	i = 0;
	while (shell->envp && shell->envp[i])
	{
		if (ft_strncmp(shell->envp[i], name, ft_strlen(name)) == 0
			&& shell->envp[i][ft_strlen(name)] == '=')
		{
			free(shell->envp[i]);
			shell->envp[i] = new_entry;
			return (1);
		}
		i++;
	}
	return (0);
}
