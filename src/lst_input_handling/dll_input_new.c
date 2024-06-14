#include "minishell.h"

t_input	*dll_input_new(char *content)
{
	t_input	*new;

	new = ft_calloc(1, sizeof(t_input));
	if (!new)
		return (NULL);
	new->content = content;
	new->args = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}