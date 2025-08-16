#include "minishell.h"

typedef struct s_int_var
{
	int word_count;
	int word_idx;
	int i;

} t_int_var;
char **split_on_whitespace(char *str)
{
	t_int_var intj;

	char *word;
	char **result;

	result = init_split_array(str, &intj.word_count);
	if (!result)
		return NULL;
	intj.word_idx = 0;
	intj.i = 0;
	while ((word = extract_word(str, &intj.i)) != NULL) // todo: norm error
	{
		result[intj.word_idx] = word;
		if (!result[intj.word_idx])
		{
			free_split_array(result);
			return NULL;
		}
		intj.word_idx++;
	}
	result[intj.word_idx] = NULL;
	return result;
}
