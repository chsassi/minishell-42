#include "minishell.h"

char	**create_mtx_from_input(t_parsing parsing)
{
	char	**res;

	res = ft_calloc((count_words(parsing.input) + 1), sizeof(char *));
	if (!res || !parsing.input)
		return (NULL);
	res = new_string (res, parsing.input);
	return (res);
}

// t_parsing	parse_input(t_parsing parsing)
// {
// 	int		i;
	
// 	i = 0;
// 	parsing.mtx_from_input = create_mtx_from_input(parsing);
// }