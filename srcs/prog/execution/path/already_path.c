/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:55:49 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 16:57:48 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*already_path(char *cmd)
{
	char	*cmd_found;

	cmd_found = NULL;
	if (ft_strchr(cmd, '/'))
	{
		if (is_executable(cmd))
		{
			cmd_found = ft_strdup(cmd);
			if (!cmd_found)
				return (NULL);
			return (cmd_found);
		}
	}
	return (NULL);
}
