/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:13:12 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:13:13 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_env_var(t_minishell *shell, char *content, char *result, int *i)
{
	char	*var_name;
	char	*var_value;

	(*i)++;
	var_name = extract_var_name(content, i);
	var_value = get_env_value(shell->env, var_name, NULL);
	if (var_value == NULL)
		result = append_to_result(result, "");
	else
		result = append_to_result(result, var_value);
	free(var_name);
	return (result);
}
