#include "minishell.h"

int	main(int ac, char **av, char **environ)
{
	t_minishell	ms;

	(void) ac;
	(void) av;
	setup_signals_parent ();
	init (&ms, environ, av[0]);
	main_loop (&ms);
	rl_clear_history ();
	return (0);
}
