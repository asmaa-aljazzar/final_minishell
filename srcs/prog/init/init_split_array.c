/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_split_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:15:21 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:15:21 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**init_split_array(char *str, int *word_count)
{
	char	**result;

	if (!str || !*str)
		return (NULL);
	*word_count = count_words_in_string(str);
	if (*word_count == 0)
		return (NULL);
	result = ft_calloc(*word_count + 1, sizeof(char *));
	if (!result)
		return (NULL);
	return (result);
}
