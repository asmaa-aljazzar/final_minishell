/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_signals_child.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 13:47:16 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 13:47:16 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setup_sig_exc(int sig, void (*handler)(int))
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(sig, &sa, NULL);
}

void	setup_signals_child(void)
{
	setup_sig_exc(SIGINT, SIG_DFL);
	setup_sig_exc(SIGQUIT, SIG_DFL);
}

void	handlequit(int sig)
{
	(void)sig;
	write(2, "Quit (core dumped)\n", 20);
}

void	handle_c(int sig)
{
	(void)sig;
	write(1, "\n", 1);
}
