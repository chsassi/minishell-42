#include "minishell.h"

void	dll_input_addfront(t_dll_input **lst, t_dll_input *new)
{
	t_dll_input	*head;

	head = *lst;
	if (!lst || !new)
		return ;
	if (!head)
	{
		new->prev = NULL;
		new->next = NULL;
		new->index = 0;
		*lst = new;
		return ;
	}
	new->next = head;
	new->prev = NULL;
	head->prev = new;
	new->index = 0;
	*lst = new;
	dll_input_set_index(lst);
}