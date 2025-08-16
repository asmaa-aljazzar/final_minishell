/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 13:05:50 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 13:05:50 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_on_whitespace(char *str)
{
	t_int_var	intj;
	char		*word;
	char		**result;

	result = init_split_array(str, &intj.word_count);
	if (!result)
		return (NULL);
	intj.word_idx = 0;
	intj.i = 0;
	while ((word = extract_word(str, &intj.i)) != NULL)
	{
		result[intj.word_idx] = word;
		if (!result[intj.word_idx])
		{
			free_split_array(result);
			return (NULL);
		}
		intj.word_idx++;
	}
	result[intj.word_idx] = NULL;
	return (result);
}
