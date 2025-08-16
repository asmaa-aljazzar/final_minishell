/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_exit_code.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:13:15 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:13:16 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_exit_code(t_minishell *shell, char *result, int *i)
{
	char	*itoa_result;

	itoa_result = ft_itoa(shell->exit_code);
	result = append_to_result(result, itoa_result);
	free(itoa_result);
	*i += 2;
	return (result);
}
