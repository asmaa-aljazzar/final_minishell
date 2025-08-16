/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_envp_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:23:11 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:23:40 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_envp_array(t_minishell *shell, char *name, char *value)
{
	char	*new_entry;

	if (!name || !value)
		return (0);
	new_entry = build_envp_entry(name, value);
	if (!new_entry)
		return (0);
	if (!replace_existing_envp(shell, name, new_entry))
	{
		if (!append_envp(shell, new_entry))
			return (0);
	}
	return (1);
}
