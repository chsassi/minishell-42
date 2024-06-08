#include "minishell.h"

t_input	*dll_input_last(t_input *lst)
{
	t_input	*new;

	if (!lst)
		return (NULL);
	new = lst;
	while (new->next != NULL)
		new = new->next;
	return (new);
}
