/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:13:09 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:13:10 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_heredoc_pipe(char *content)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		return (-1);
	if (content && ft_strlen(content) > 0)
	{
		if (write(pipefd[1], content, ft_strlen(content)) == -1)
		{
			close(pipefd[0]);
			close(pipefd[1]);
			return (-1);
		}
	}
	close(pipefd[1]);
	return (pipefd[0]);
}
