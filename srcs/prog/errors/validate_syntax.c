/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:36:52 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 16:37:52 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	validate_syntax(t_minishell *ms)
{
	int	i;

	i = 0;
	while (ms->tok[i])
	{
		if (ms->tok[i]->type == PIPE)
		{
			if (!check_pipe_syntax(ms, i))
				return (0);
		}
		else if ((ms->tok[i]->type == T_INPUT
				|| ms->tok[i]->type == T_HEREDOC
				|| ms->tok[i]->type == T_OUTPUT
				|| ms->tok[i]->type == T_APPEND)
			&& (ms->tok[i + 1] && ms->tok[i + 1]->type != PIPE))
		{
			if (!check_redirection_syntax(ms, &i))
				return (0);
		}
		i++;
	}
	return (1);
}
