/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_to_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:20:32 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:20:32 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_to_free(t_minishell *minishell)
{
	if (minishell->cmd)
	{
		free_commands(minishell);
		minishell->cmd = NULL;
	}
	if (minishell->tok)
	{
		free_tokens(minishell->tok);
		minishell->tok = NULL;
	}
	if (minishell->input)
	{
		free(minishell->input);
		minishell->input = NULL;
	}
	if (minishell->mini_file)
	{
		free(minishell->mini_file);
		minishell->mini_file = NULL;
	}
}
