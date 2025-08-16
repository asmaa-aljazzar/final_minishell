
#include "minishell.h"

void	print_re(t_redirection *re)
{
	while (re)
	{
		printf("%s\n", re->file);
		re = re->next;
	}
}

void free_redirections(t_redirection *redir)
{
	t_redirection *current;
	t_redirection *next;

	current = redir;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_commands(t_minishell *minishell)
{
	t_command	*current;
	t_command	*next;

	current = minishell->cmd;
	while (current)
	{
		next = current->next;
		if (current->argv)
			free(current->argv);
		if (current->argv_expanded)
			free(current->argv_expanded);
		if (current->redir)
			free_redirections(current->redir);
		free(current);
		current = next;
	}
	minishell->cmd = NULL;
}
