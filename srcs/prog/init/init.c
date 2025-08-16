
#include "minishell.h"

void	init(t_minishell *ms, char **environ, char *argv)
{
	ms->tok = NULL;
	ms->input = NULL;
	ms->cmd = NULL;
	ms->tokens_count = 0;
	ms->pipe_count = 0;                  
	ms->exit_code = 0;
	ms->skip_execution = 0;
	ms->mini_file = ft_strdup(argv);
	if (!ms->mini_file)
		exit(1);
	ms->envp = ft_strdup_double(environ);
	if (!ms->envp)
	{
		free(ms->mini_file);
		exit(1);
	}
	ms->env = init_env(ms, environ);
	if (!ms->env)
	{
		free(ms->mini_file);
		free_2d(ms->envp);
		exit(1);
	}
	ms->in_single_quote = 0;                
	ms->in_double_quote = 0;          
	ft_memset(ms->buff, 0, sizeof(ms->buff));
	if (!increase_SHLVL_var(ms, ms->env))
	{
		free(ms->mini_file);
		free_2d(ms->envp);
		free_env(ms->env);
		exit(1);
	}
	ms->last_token_end = -1;
}
