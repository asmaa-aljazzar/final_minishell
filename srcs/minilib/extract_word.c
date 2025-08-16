#include "minishell.h"

char *extract_word(char *str, int *index)//todo: ask mohammad
{
    int i = *index;
    while (str[i] && is_whitespace(str[i]))
        i++;
    if (!str[i])
        return NULL;
    int start = i;
    while (str[i] && !is_whitespace(str[i]))
        i++;
    *index = i;
    return (ft_substr(str, start, i - start));
}
