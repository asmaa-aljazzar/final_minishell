/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_heredoc_readline.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:14:54 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:15:00 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_heredoc_readline(int fd, char *line, char *delimiter)
{
	if (g_signal_received == SIGINT)
	{
		if (line)
			free(line);
		return (-1);
	}
	if (!line)
	{
		print_eof_warning(delimiter);
		return (-1);
	}
	if (is_delimiter_line(line, delimiter))
	{
		free(line);
		return (-1);
	}
	write(fd, line, strlen(line));
	write(fd, "\n", 1);
	free(line);
	return (0);
}
