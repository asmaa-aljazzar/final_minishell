#include "minishell.h"

int process_heredoc(t_minishell *shell, char *delimiter)
{
    int read_fd;
    int should_expand;
      
    should_expand = should_expand_heredoc(shell, delimiter);
    read_fd = read_heredoc_content(shell, delimiter, should_expand);
    if (read_fd == -1)
    {
        if (g_signal_received == SIGINT)
        {
            shell->exit_code = 130;
        }
        else
            shell->exit_code = 1;
        return (0);
    }
 
    return (read_fd);
}
