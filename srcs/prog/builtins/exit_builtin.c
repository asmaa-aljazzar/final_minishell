/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:11:07 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 16:11:08 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	validate_exit_arg(const char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	handle_exit(t_minishell *minishell, int exit_code)
{
	check_to_free(minishell);
	free_env(minishell->env);
	free_2d(minishell->envp);
	rl_clear_history();
	exit(exit_code);
}

static int	get_exit_arg_count(t_command *cmd)
{
	int	count;

	count = 0;
	if (!cmd || !cmd->argv)
		return (0);
	while (cmd->argv[count])
		count++;
	return (count - 1);
}

static void	exit_with_numeric(t_minishell *minishell, const char *arg)
{
	int	exit_code;

	if (validate_exit_arg(arg))
	{
		exit_code = ft_atoi(arg) % 256;
		handle_exit(minishell, exit_code);
	}
	else
	{
		ft_putendl_fd("minishell: exit: %s: numeric argument required\n", 2);
		handle_exit(minishell, 2);
	}
}

static void	handle_multiple_args(t_minishell *minishell, const char *arg)
{
	if (validate_exit_arg(arg))
	{
		ft_putendl_fd("minishell: exit: too many arguments\n", 2);
		minishell->exit_code = 1;
	}
	else
		exit_with_numeric(minishell, arg);
}

void	exit_builtin(t_minishell *minishell)
{
	int	arg_count;

	arg_count = get_exit_arg_count(minishell->cmd);
	if (minishell->pipe_count == 0)
		ft_putendl_fd("exit", 2);
	if (arg_count == 0)
		handle_exit(minishell, 0);
	else if (arg_count == 1)
		exit_with_numeric(minishell, minishell->cmd->argv[1]);
	else
		handle_multiple_args(minishell, minishell->cmd->argv[1]);
}
