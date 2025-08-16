/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection_syntax.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:36:37 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 16:36:45 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redirection_syntax(t_minishell *ms, int *i)
{
	if (ms->tok[*i] && (!ms->tok[*i + 1] || ms->tok[*i + 1]->type != T_WORD))
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `<>'", 2);
		ms->exit_code = 2;
		return (0);
	}
	(*i)++;
	return (1);
}
