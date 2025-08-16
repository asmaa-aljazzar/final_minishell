/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:21:53 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:21:53 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_minishell *shell, char *msg, int status)
{
	if (msg && *msg)
		ft_putendl_fd(msg, STDERR_FILENO);
	free_complex_resources(shell);
	rl_clear_history();
	shell->exit_code = status;
	exit(status);
}
