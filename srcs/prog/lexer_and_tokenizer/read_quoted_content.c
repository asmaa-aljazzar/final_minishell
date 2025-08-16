/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_quoted_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:09:06 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:09:06 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_quoted_content(t_minishell *ms, int *i, char quote)
{
	int		start;
	int		size;
	char	*word;

	start = ++(*i);
	while (ms->input[*i] && ms->input[*i] != quote)
		(*i)++;
	if (ms->input[*i] != quote)
	{
		ft_putendl_fd("minishell: syntax error: unmatched quote",
			STDERR_FILENO);
		ms->exit_code = 2;
		return (NULL);
	}
	size = *i - start;
	word = malloc(size + 1);
	if (!word)
		ft_exit(ms, "minishell: Memory allocation failed", 1);
	ft_strlcpy(word, &ms->input[start], size + 1);
	return (word);
}
