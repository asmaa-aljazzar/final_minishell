
#include "minishell.h"

char    *get_path(t_minishell *shell, char **argv)
{
    char    *path_env;
    char    *path_copy;
    char    *path;

    path_env = NULL;
    path_copy = NULL;
    if (!argv || !argv[0])
        return (NULL);
    if((path = already_path(argv[0]))) //if input is already  /usr/bin/cat
    {
            if(!path)
                return (NULL);
        return(path);
    }
    path_env = find_path(shell->env);
    if (!path_env)
        return (NULL);
    path_copy = ft_strdup(path_env);
    if (!path_copy)
        return (NULL);
    path = find_cmd_path(argv[0], path_copy);
    free(path_copy);
    return (path);
}
