/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 13:04:34 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 13:04:34 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_word(char *str, int *index) // todo: ask mohammad
{
	int	i;
	int	start;

	i = *index;
	while (str[i] && is_whitespace(str[i]))
		i++;
	if (!str[i])
		return (NULL);
	start = i;
	while (str[i] && !is_whitespace(str[i]))
		i++;
	*index = i;
	return (ft_substr(str, start, i - start));
}
