/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal-moh <baal-moh@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 11:06:48 by baal-moh          #+#    #+#             */
/*   Updated: 2025-08-16 11:06:48 by baal-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	append_and_free(char **result, char *to_add)
{
	char	*temp;

	temp = *result;
	*result = ft_strjoin(*result, to_add);
	free(temp);
	free(to_add);
}
