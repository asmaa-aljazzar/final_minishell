/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_literal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:22:50 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:27:31 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_literal(char *token, size_t *i)
{
	size_t	start;

	start = *i;
	while (token[*i] && token[*i] != '$')
		(*i)++;
	return (ft_substr(token, start, *i - start));
}
