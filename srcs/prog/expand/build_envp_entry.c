/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_envp_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:22:21 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:22:22 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*build_envp_entry(char *name, char *value)
{
	char	*temp;
	char	*entry;

	temp = ft_strjoin(name, "=");
	if (!temp)
		return (NULL);
	entry = ft_strjoin(temp, value);
	free(temp);
	if (!entry)
		return (NULL);
	return (entry);
}
