#include "minishell.h"

void setup_sig_exc(int sig, void(*handler)(int))
{
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sigaction(sig, &sa, NULL);
}

void setup_signals_child(void)
{
    setup_sig_exc(SIGINT, SIG_DFL);
    setup_sig_exc(SIGQUIT,SIG_DFL);
}
void handlequit(int sig)
{
    (void)sig;
    write(2, "Quit (core dumped)\n", 20);
}
void handle_c(int sig)
{
    (void)sig;
    write(1, "\n", 1);
}
