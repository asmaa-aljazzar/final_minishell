/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_delimiter_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:13:23 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:16:59 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_delimiter_line(char *line, char *delimiter)
{
	size_t	del_len;

	del_len = ft_strlen(delimiter);
	if (ft_strncmp(line, delimiter, del_len) == 0
		&& ft_strlen(line) == del_len)
		return (1);
	return (0);
}
