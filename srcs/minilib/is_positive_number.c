/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_positive_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 13:05:20 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 13:05:20 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_positive_number(const char *s)
{
	if (!s || !*s)
		return (0);
	while (*s)
		if (!ft_isdigit(*s++))
			return (0);
	return (1);
}
