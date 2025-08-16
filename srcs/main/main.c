/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 12:59:46 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 12:59:46 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **environ)
{
	t_minishell	ms;

	(void)ac;
	setup_signals_parent();
	init(&ms, environ, av[0]);
	main_loop(&ms);
	rl_clear_history();
	return (0);
}
