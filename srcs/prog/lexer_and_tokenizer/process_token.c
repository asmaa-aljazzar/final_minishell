/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:09:02 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:09:02 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_token(t_minishell *ms, int *k, int *i)
{
	int	glued;

	glued = update_glued(ms, i, *k);
	if (glued == -1)
		return (0);
	if (!select_tokenizer(ms, k, i, glued))
		return (0);
	return (1);
}
