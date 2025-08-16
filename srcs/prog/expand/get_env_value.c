/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:22:53 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:27:47 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(t_env *env, const char *var, char *argv)
{
	if (argv && ft_strcmp(var, "0") == 0)
		return (argv);
	while (env)
	{
		if (ft_strncmp(env->name, var, ft_strlen(env->name) + 1) == 0)
			return (env->value);
		env = env->next;
	}
	return ("");
}
