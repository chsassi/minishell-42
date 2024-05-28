#include "minishell.h"

t_dll_input	*dll_input_new(char *content)
{
	t_dll_input	*new;

	new = ft_calloc(1, sizeof(t_dll_input));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}