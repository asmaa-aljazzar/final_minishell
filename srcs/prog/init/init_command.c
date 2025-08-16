/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:15:02 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:15:02 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*init_command(t_minishell *ms)
{
	t_command	*new;

	new = malloc(sizeof(t_command));
	if (!new)
		ft_exit(ms, "malloc failed", EXIT_FAILURE);
	new->argv = NULL;
	new->argv_expanded = NULL;
	new->redir = NULL;
	new->next = NULL;
	return (new);
}
