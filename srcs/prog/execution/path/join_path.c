#include "minishell.h"

char *join_path(const char *path, const char *cmd)
{
    char *result;
    char *temp;

    temp = NULL;
    if (!path || !cmd)
        return (NULL);
    temp = ft_strjoin(path, "/");
    if (!temp)
        return (NULL);
    result = ft_strjoin(temp, cmd);
    free (temp);
    return (result);
}
