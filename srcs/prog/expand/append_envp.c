/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:20:19 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:22:09 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	append_envp(t_minishell *shell, char *new_entry)
{
	int		count;
	int		i;
	char	**new_envp;

	count = 0;
	while (shell->envp && shell->envp[count])
		count++;
	new_envp = malloc(sizeof(char *) * (count + 2));
	if (!new_envp)
	{
		free(new_entry);
		return (0);
	}
	i = 0;
	while (i < count)
	{
		new_envp[i] = shell->envp[i];
		i++;
	}
	new_envp[count] = new_entry;
	new_envp[count + 1] = NULL;
	free(shell->envp);
	shell->envp = new_envp;
	return (1);
}
