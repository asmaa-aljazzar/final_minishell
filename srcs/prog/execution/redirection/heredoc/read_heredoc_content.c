/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:15:16 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:15:45 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	yaman_sig(int sig)
{
	(void)sig;
	g_signal_received = SIGINT;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	close(0);
}

int	read_heredoc_content(t_minishell *shell, char *delimiter, int should_expand)
{
	int					fd[2];
	struct sigaction	sa;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	sa.sa_handler = yaman_sig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	read_until_delimiter(shell, delimiter, fd[1], should_expand);
	close(fd[1]);
	return (fd[0]);
}
