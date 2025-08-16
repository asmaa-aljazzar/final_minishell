/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_SHLVL_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:23:04 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:29:52 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	increase_shlvl_var(t_minishell *ms, t_env *env)
{
	char	*new;
	char	*old;
	int		lvl;

	old = get_env_value(env, "SHLVL", NULL);
	if (is_positive_number(old))
		lvl = ft_atoi(old) + 1;
	else
		lvl = 1;
	new = ft_itoa(lvl);
	if (!new)
		return (0);
	if (!update_env_var(ms, "SHLVL", new))
	{
		free(new);
		return (0);
	}
	if (!update_envp_array(ms, "SHLVL", new))
	{
		free(new);
		return (0);
	}
	free(new);
	return (1);
}
