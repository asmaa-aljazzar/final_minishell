/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe_syntax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:35:37 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 16:36:17 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_pipe_syntax(t_minishell *ms, int i)
{
	if (i == 0 && ms->tok[i] && ((ms->tok[i + 1] && ms->tok[i
					+ 1]->type != PIPE) || !ms->tok[i + 1]))
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
		ms->exit_code = 2;
		return (0);
	}
	if (!ms->tok[i + 1])
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
		ms->exit_code = 2;
		return (0);
	}
	if (ms->tok[i + 1] && ms->tok[i + 1]->type == PIPE)
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `||'", 2);
		ms->exit_code = 2;
		return (0);
	}
	return (1);
}
