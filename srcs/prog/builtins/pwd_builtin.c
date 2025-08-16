/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:26:12 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 16:32:52 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_builtin(t_minishell *shell)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		write(STDOUT_FILENO, cwd, ft_strlen(cwd));
		write(STDOUT_FILENO, "\n", 1);
		free(cwd);
	}
	else
	{
		perror("getcwd() error");
		shell->exit_code = 1;
	}
}
