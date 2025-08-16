/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_empty_expansion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:22:58 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:28:35 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_empty_expansion(char *token)
{
	if (!token)
		return (ft_strdup(""));
	if (ft_strcmp(token, "$") == 0)
		return (ft_strdup("$"));
	if (token[0] == '\0')
		return (ft_strdup(""));
	return (NULL);
}
