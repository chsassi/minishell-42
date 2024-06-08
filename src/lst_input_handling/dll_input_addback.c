#include "minishell.h"

void	dll_input_addback(t_input **lst, t_input *new)
{	
	t_input	*last;

	if (!lst || !new)
		return ;
	last = dll_input_last(*lst);
	if (!(*lst))
	{
		new->prev = NULL;
		new->next = NULL;
		*lst = new;
		return ;
	}
	new->prev = last;
	new->next = NULL;
	last->next = new;
}
