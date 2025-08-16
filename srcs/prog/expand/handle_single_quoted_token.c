/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_single_quoted_token.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:23:02 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:23:03 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_single_quoted_token(t_token *token, t_token **new_tokens,
		int *new_count)
{
	token->expanded = 0;
	new_tokens[(*new_count)++] = token;
}
