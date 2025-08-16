
#include "minishell.h"

t_command *create_command_list(t_minishell *ms, int count)
{
    t_command *head;
    t_command *curr;
    t_command *new;
    int i;

    head = NULL;
    curr = NULL;
    i = 0;
    while (i <= count)
    {
        new = init_command(ms);
        if (!head)
        {
            head = new;
            curr = new;
        }
        else
        {
            curr->next = new;
            curr = new;
        }
        i++;
    }
    return head;
}

// void allocate_commands(t_minishell *ms) this function adds extra step only
// {
//     ms->cmd = create_command_list(ms, ms->pipe_count); 
// }