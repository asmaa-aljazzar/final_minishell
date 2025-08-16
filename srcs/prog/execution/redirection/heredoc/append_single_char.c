/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_single_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:13:03 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:16:26 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*append_single_char(char *result, char c)
{
	char	str[2];
	char	*append;

	str[0] = c;
	str[1] = '\0';
	append = append_to_result(result, str);
	return (append);
}
