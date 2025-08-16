/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_token_to_argvs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 11:11:10 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 11:11:10 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_token_to_argvs(t_minishell *ms, t_command *cmd, t_token *tok,
		int arg_idx)
{
	cmd->argv[arg_idx] = tok->word;
	if (!cmd->argv[arg_idx])
		ft_exit(ms, "malloc failed", EXIT_FAILURE);
	cmd->argv_expanded[arg_idx] = tok->expanded;
}
