#include "minishell.h"

void	dll_input_addback(t_dll_input **lst, t_dll_input *new)
{
	t_dll_input	*last;
	int		    index;

	if (!lst || !new)
		return ;
	index = dll_input_size(*lst);
	last = dll_input_last(*lst);
	if (!(*lst))
	{
		new->prev = NULL;
		new->next = NULL;
		new->index = 0;
		*lst = new;
		return ;
	}
	new->prev = last;
	new->next = NULL;
	new->index = index;
	last->next = new;
}