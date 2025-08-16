/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:15:13 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:15:14 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_heredoc(t_minishell *shell, char *delimiter)
{
	int	read_fd;
	int	should_expand;

	should_expand = should_expand_heredoc(shell, delimiter);
	read_fd = read_heredoc_content(shell, delimiter, should_expand);
	if (read_fd == -1)
	{
		if (g_signal_received == SIGINT)
			shell->exit_code = 130;
		else
			shell->exit_code = 1;
		return (0);
	}
	return (read_fd);
}
