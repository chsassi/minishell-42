#include "minishell.h"

t_dll_input	*dll_input_last(t_dll_input *lst)
{
	t_dll_input	*new;

	if (!lst)
		return (NULL);
	new = lst;
	while (new->next != NULL)
		new = new->next;
	return (new);
}