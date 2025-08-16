/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_eof_warning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:13:29 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:17:33 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_eof_warning(char *delimiter)
{
	ft_putstr_fd(
		"minishell: warning: here-document delimited by end-of-file (wanted `",
		2);
	ft_putstr_fd(delimiter, 2);
	ft_putendl_fd("')", 2);
}
