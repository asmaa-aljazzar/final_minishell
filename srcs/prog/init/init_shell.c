/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:15:14 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:15:14 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	initialize_fields(t_minishell *ms)
{
	ms->tok = NULL;
	ms->tokens_count = 0;
	ms->pipe_count = 0;
	ms->pids = NULL;
	ms->pipes = NULL;
}

static int	read_input_and_process(t_minishell *ms)
{
	int	i;

	i = 0;
	ms->input = readline(PROMPT);
	if (!ms->input)
	{
		handle_eof(ms);
		return (0);
	}
	if (!*ms->input)
	{
		free(ms->input);
		ms->input = NULL;
		return (0);
	}
	while (ms->input[i])
	{
		if (!is_whitespace(ms->input[i]))
			break ;
		i++;
	}
	add_history(ms->input);
	if (!ms->input[i])
		return (0);
	if (g_signal_received == SIGINT)
		ms->exit_code = 130;
	g_signal_received = SIG_NONE;
	return (1);
}

static int	read_and_prepare_input(t_minishell *ms)
{
	initialize_fields(ms);
	return (read_input_and_process(ms));
}

static int	process_input_and_validate(t_minishell *ms)
{
	if (!get_tokens(ms))
	{
		free(ms->input);
		ms->input = NULL;
		return (0);
	}
	if (!validate_syntax(ms))
	{
		check_to_free(ms);
		ms->exit_code = 2;
		return (0);
	}
	return (1);
}

int	init_shell(t_minishell *ms)
{
	check_to_free(ms);
	if (!read_and_prepare_input(ms))
		return (1);
	if (!process_input_and_validate(ms))
		return (1);
	return (0);
}
