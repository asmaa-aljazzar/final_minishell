/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_output_redir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 14:09:28 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 14:09:28 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenize_output_redir(t_minishell *ms, int *k, int *i)
{
	if (ms->input[*i + 1] == '>')
		handle_output_append_redir(ms, k, i);
	else
		handle_output_file_redir(ms, k, i);
	ms->last_token_end = *i - 1;
}
