/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:44:51 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 16:44:52 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_commands(t_minishell *ms)
{
	if (g_signal_received != 2)
	{
		if (ms->pipe_count == 0)
			execute_single_command(ms);
		else
			execute_piped_commands(ms, ms->pipe_count + 1);
	}
}
