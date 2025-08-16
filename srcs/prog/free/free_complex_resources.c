
#include "minishell.h"

void	free_complex_resources(t_minishell *shell)
{
	if (shell->cmd)
	{
		free_commands(shell);
		shell->cmd = NULL;
	}
	if (shell->tok)
	{
		free_tokens(shell->tok);
		shell->tok = NULL;
	}
	if (shell->env)
	{
		free_env(shell->env);
		shell->env = NULL;
	}
	if (shell->envp)
	{
		free_2d(shell->envp);
		shell->envp = NULL;
	}
	if (shell->mini_file)
	{
		free(shell->mini_file);
		shell->mini_file = NULL;
	}
	if (shell->input)
	{
		free(shell->input);
		shell->input = NULL;	
	}
	if (shell->pids)
		free (shell->pids);
	if (shell->pipes)
		free (shell->pipes);
}

void free_simple_resources(t_minishell *shell)
{
	if (shell->cmd)
	{
		free_commands(shell);
		shell->cmd = NULL;
	}
	if (shell->tok)
	{
		free_tokens(shell->tok);
		shell->tok = NULL;
	}
	if (shell->input)
	{
		free(shell->input);
		shell->input = NULL;	
	}
	if (shell->pids)
	{
		free(shell->pids);
		shell->pids = NULL;
	}
	if (shell->pipes)
	{
		free(shell->pipes);
		shell->pipes = NULL;
	}
}
