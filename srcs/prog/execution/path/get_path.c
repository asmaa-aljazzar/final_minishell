/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:56:02 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 16:57:28 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path(t_minishell *shell, char **argv)
{
	char	*path_env;
	char	*path_copy;
	char	*path;

	path_env = NULL;
	path_copy = NULL;
	if (!argv || !argv[0])
		return (NULL);
	path = already_path(argv[0]);
	if (path)
		return (path);
	else
		return (NULL);
	path_env = find_path(shell->env);
	if (!path_env)
		return (NULL);
	path_copy = ft_strdup(path_env);
	if (!path_copy)
		return (NULL);
	path = find_cmd_path(argv[0], path_copy);
	free(path_copy);
	return (path);
}
