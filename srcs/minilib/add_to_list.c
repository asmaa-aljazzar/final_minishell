/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 11:06:28 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 11:06:28 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**add_to_list(char **old_list, char *value)
{
	int		len;
	char	**new_list;
	int		i;

	len = 0;
	while (old_list && old_list[len])
		len++;
	new_list = malloc(sizeof(char *) * (len + 2));
	if (!new_list)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_list[i] = old_list[i];
		i++;
	}
	new_list[len] = ft_strdup(value);
	new_list[len + 1] = NULL;
	free(old_list);
	return (new_list);
}
