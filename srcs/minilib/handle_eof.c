/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_eof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 13:04:27 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 13:04:27 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_eof(t_minishell *minishell)
{
	write(1, "exit\n", 5);
	free_env(minishell->env);
	free_2d(minishell->envp);
	rl_clear_history();
	exit(0);
}
