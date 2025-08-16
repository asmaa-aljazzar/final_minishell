/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 12:59:24 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 12:59:24 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_loop(t_minishell *ms)
{
	print_banner();
	while (1)
	{
		if (!isatty(0))
			dup2(2, 0);
		setup_signals_readline();
		if (init_shell(ms) == 1)
			continue ;
		if (prepare_command_processing(ms) < 0)
			continue ;
		execute_commands(ms);
	}
}
