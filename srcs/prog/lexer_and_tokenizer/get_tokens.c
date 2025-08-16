/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:08:27 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:08:27 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_tokens(t_minishell *ms)
{
	size_t	len;
	int		i;
	int		k;

	len = ft_strlen(ms->input);
	i = 0;
	k = 0;
	ms->tok = ft_calloc(len + 1, sizeof(t_token *));
	if (!ms->tok)
		ft_exit(ms, "malloc failed", 1);
	ms->in_single_quote = 0;
	ms->in_double_quote = 0;
	while (ms->input[i])
	{
		while (ms->input[i] == ' ')
			i++;
		if (!ms->input[i])
			break ;
		if (!process_token(ms, &k, &i))
			return (0);
	}
	ms->tok[k] = NULL;
	ms->tokens_count = k;
	return (1);
}
