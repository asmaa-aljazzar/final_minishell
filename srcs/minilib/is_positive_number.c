#include "minishell.h"

int is_positive_number(const char *s)
{ 
	if (!s || !*s)
		return (0); 
	while (*s)
		if (!ft_isdigit(*s++))
			return (0);
	return (1);
}