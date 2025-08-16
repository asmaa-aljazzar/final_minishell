/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:55:56 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 16:56:22 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path(t_env *env)
{
	while (env)
	{
		if (strncmp(env->name, "PATH", 4) == 0)
			return (env->value);
		env = env->next;
	}
	ft_putendl_fd("PATH not found\n", 2);
	return (NULL);
}
