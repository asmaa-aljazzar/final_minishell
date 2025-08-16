/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 11:09:08 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 11:09:08 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*append_result(char *old_result, char *value)
{
	char	*temp;
	char	*new_result;

	temp = old_result;
	new_result = ft_strjoin(old_result, value);
	free(temp);
	return (new_result);
}
