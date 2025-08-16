/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:43:30 by aaljazza          #+#    #+#             */
/*   Updated: 2025/08/16 16:30:20 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_builtin_check_args(t_command *cmd, t_minishell *shell)
{
	if (cmd->argv[1] && cmd->argv[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", STDERR_FILENO);
		shell->exit_code = 1;
		return (1);
	}
	return (0);
}

int	cd_builtin_resolve_path_home(t_minishell *shell, t_cd_path *cdp)
{
	cdp->path = get_env_value(shell->env, "HOME", NULL);
	cdp->display_path = "HOME";
	if (!cdp->path)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
		shell->exit_code = 1;
		return (-1);
	}
	return (0);
}

char	*cd_builtin_get_home(t_minishell *shell)
{
	char	*home;

	home = get_env_value(shell->env, "HOME", NULL);
	if (!home)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
		shell->exit_code = 1;
	}
	return (home);
}

void	cd_builtin_tilde_plain(t_cd_path *cdp, const char *arg, char *home)
{
	cdp->path = home;
	cdp->display_path = (char *)arg;
}

int	cd_builtin_tilde_slash(t_minishell *shell, t_cd_path *cdp, const char *arg,
		char *home)
{
	cdp->expanded_path = ft_strjoin(home, arg + 1);
	if (!cdp->expanded_path)
	{
		ft_putstr_fd("minishell: cd: memory allocation failed\n",
			STDERR_FILENO);
		shell->exit_code = 1;
		return (-1);
	}
	cdp->path = cdp->expanded_path;
	cdp->display_path = cdp->expanded_path;
	return (0);
}

void	cd_builtin_tilde_fallback(t_cd_path *cdp, const char *arg)
{
	cdp->path = (char *)arg;
	cdp->display_path = (char *)arg;
}

int	cd_builtin_resolve_path_tilde(t_minishell *shell, t_cd_path *cdp,
		const char *arg)
{
	char	*home;

	home = cd_builtin_get_home(shell);
	if (!home)
		return (-1);
	if (arg[1] == '\0')
		cd_builtin_tilde_plain(cdp, arg, home);
	else if (arg[1] == '/')
		return (cd_builtin_tilde_slash(shell, cdp, arg, home));
	else
		cd_builtin_tilde_fallback(cdp, arg);
	return (0);
}

int	cd_builtin_resolve_path_oldpwd(t_minishell *shell, t_cd_path *cdp)
{
	cdp->path = get_env_value(shell->env, "OLDPWD", NULL);
	cdp->display_path = "-";
	if (!cdp->path)
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", STDERR_FILENO);
		shell->exit_code = 1;
		return (-1);
	}
	ft_putstr_fd(cdp->path, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}

int	cd_builtin_resolve_path(t_minishell *shell, t_command *cmd, t_cd_path *cdp)
{
	cdp->path = NULL;
	cdp->display_path = NULL;
	cdp->expanded_path = NULL;
	if (!cmd->argv[1] || ft_strncmp(cmd->argv[1], "--", 3) == 0)
		return (cd_builtin_resolve_path_home(shell, cdp));
	else if (cmd->argv[1][0] == '~')
		return (cd_builtin_resolve_path_tilde(shell, cdp, cmd->argv[1]));
	else if (ft_strncmp(cmd->argv[1], "-", 2) == 0)
		return (cd_builtin_resolve_path_oldpwd(shell, cdp));
	else
	{
		cdp->path = cmd->argv[1];
		cdp->display_path = cmd->argv[1];
		return (0);
	}
}

int	cd_builtin_change_dir(t_minishell *shell, t_cd_path *cdp, char *oldpwd)
{
	if (chdir(cdp->path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(cdp->display_path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		if (errno == ENOENT)
			ft_putstr_fd("No such file or directory\n", STDERR_FILENO);
		else if (errno == EACCES)
			ft_putstr_fd("Permission denied\n", STDERR_FILENO);
		else if (errno == ENOTDIR)
			ft_putstr_fd("Not a directory\n", STDERR_FILENO);
		else
			ft_putstr_fd("Error\n", STDERR_FILENO);
		shell->exit_code = 1;
		free(oldpwd);
		if (cdp->expanded_path)
			free(cdp->expanded_path);
		return (-1);
	}
	return (0);
}

void	cd_builtin_update_env(t_minishell *shell, char *oldpwd, t_cd_path *cdp)
{
	char	*cwd;

	update_env_var(shell, "OLDPWD", oldpwd);
	free(oldpwd);
	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		update_env_var(shell, "PWD", cwd);
		free(cwd);
	}
	else
	{
		if (cdp->path && cdp->path[0] == '/')
			update_env_var(shell, "PWD", cdp->path);
		else
			update_env_var(shell, "PWD", NULL);
	}
}

char	*cd_builtin_get_oldpwd(t_minishell *shell)
{
	char	*oldpwd;

	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
	{
		ft_putendl_fd("/minishell: No such file or directory ", 2);
		shell->exit_code = 1;
	}
	return (oldpwd);
}

void	cd_builtin_cleanup(t_cd_path *cdp)
{
	if (cdp->expanded_path)
		free(cdp->expanded_path);
}

void	cd_builtin(t_minishell *shell)
{
	t_command	*cmd;
	t_cd_path	cdp;
	char		*oldpwd;

	cmd = shell->cmd;
	if (cd_builtin_check_args(cmd, shell))
		return ;
	oldpwd = cd_builtin_get_oldpwd(shell);
	if (!oldpwd)
		return ;
	if (cd_builtin_resolve_path(shell, cmd, &cdp) < 0)
	{
		free(oldpwd);
		return ;
	}
	if (cd_builtin_change_dir(shell, &cdp, oldpwd) < 0)
	{
		cd_builtin_cleanup(&cdp);
		return ;
	}
	cd_builtin_update_env(shell, oldpwd, &cdp);
	shell->exit_code = 0;
	cd_builtin_cleanup(&cdp);
}
