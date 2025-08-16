// execute_external_command.c
#include "minishell.h"
//*#### Execute external command
// • Handle absolute/relative paths
// • Reject execution of directories
// • Print clear error messages for invalid commands
void execute_external_command(t_minishell *shell, char **argv)
{
	char *cmd_path;
	struct stat st;

	if (!argv || !argv[0] || argv[0][0] == '\0')
	{
		ft_putstr_fd("minishell: ''", STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		shell->exit_code = 127;
		if (argv && shell->pipe_count)
		{
			free(argv);
			argv = NULL;
		}
		ft_exit(shell, NULL, 127);
	}
	if (ft_strcmp(argv[0], ".") == 0)
	{
		ft_putstr_fd("minishell: .: filename argument required\n", STDERR_FILENO);
		ft_putstr_fd(".: usage: . filename [arguments]\n", STDERR_FILENO);
		shell->exit_code = 2;
		if (argv && shell->pipe_count)
		{
			free(argv);
			argv = NULL;
		}
		ft_exit(shell, NULL, 2);
	}
	else if (ft_strcmp(argv[0], "..") == 0)
	{
		ft_putstr_fd("minishell: ..: command not found\n", STDERR_FILENO);
		shell->exit_code = 127;
		if (argv && shell->pipe_count)
		{
			free(argv);
			argv = NULL;
		}
		ft_exit(shell, NULL, 127);
	}

	if (ft_strchr(argv[0], '/'))
		cmd_path = argv[0];
	else
		cmd_path = get_path(shell, argv);
	if (!cmd_path)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		shell->exit_code = 127;
		if (argv && shell->pipe_count)
		{
			free(argv);
			argv = NULL;
		}
		ft_exit(shell, NULL, 127);
	}
	if (argv[0][ft_strlen(argv[0]) - 1] == '/')
	{
		if (stat(argv[0], &st) != 0 || !S_ISDIR(st.st_mode))
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(argv[0], STDERR_FILENO);
			ft_putstr_fd(": Not a directory\n", STDERR_FILENO);
			shell->exit_code = 126;
		if (argv && shell->pipe_count)
		{
			free(argv);
			argv = NULL;
		}
			ft_exit(shell, NULL, 126);
		}
	}
	if (stat(cmd_path, &st) == 0 && S_ISDIR(st.st_mode))
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putstr_fd(": Is a directory\n", STDERR_FILENO);
		shell->exit_code = 126;
		if (argv && shell->pipe_count)
		{
			free(argv);
			argv = NULL;
		}
		ft_exit(shell, NULL, 126);
	}
	execve(cmd_path, argv, shell->envp);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	perror(argv[0]);
	free_complex_resources(shell);
	if (argv && shell->pipe_count)
	{
		free(argv);
		argv = NULL;
	}
	if (errno == EACCES)
		exit(126);
	exit(127);
}
