/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_to_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:13:06 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 17:13:07 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*append_to_result(char *result, char *to_append)
{
	char	*temp;

	temp = result;
	result = ft_strjoin(result, to_append);
	free(temp);
	return (result);
}
