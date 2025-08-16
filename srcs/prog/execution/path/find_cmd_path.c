/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:55:52 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 16:58:01 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_cmd_path(char *cmd, char *path_env)
{
	char	*full_path;
	char	*token;

	token = strtok(path_env, ":");
	while (token)
	{
		full_path = join_path(token, cmd);
		if (!full_path)
			return (NULL);
		if (is_executable(full_path))
			return (full_path);
		free(full_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
