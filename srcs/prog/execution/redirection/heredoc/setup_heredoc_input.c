/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_heredoc_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:16:03 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:16:04 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	setup_heredoc_input(t_redirection *redir)
{
	int	heredoc_fd;

	heredoc_fd = redir->heredoc_fd;
	if (heredoc_fd >= 0)
	{
		if (dup2(heredoc_fd, 0) == -1)
		{
			close(heredoc_fd);
			return (-1);
		}
		close(heredoc_fd);
	}
	return (0);
}
