#include "minishell.h"

int count_max_tokens_after_expansion(t_minishell *ms)
{
    int i;
    int max;
    
    max = 0;
    i = 0;
    while (ms->tok && ms->tok[i])
    {
        if (ms->tok[i]->qtype == QUOTE_SINGLE)
            max += 1;
        else
            max += 20;
        i++;
    }
    if (max > 0)
        return max;
    else
        return (100);
}
