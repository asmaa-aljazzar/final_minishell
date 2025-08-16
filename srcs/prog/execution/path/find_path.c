
#include "minishell.h"

char    *find_path(t_env *env)
{
    while(env)
    {
        if (strncmp(env->name, "PATH", 4) == 0)
            return (env->value);
        env = env->next;
    }
    ft_putendl_fd("PATH not found\n", 2);
    return (NULL);
}