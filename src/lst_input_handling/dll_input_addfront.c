#include "minishell.h"

void	dll_input_addfront(t_input **lst, t_input *new)
{
	t_input	*head;

	head = *lst;
	if (!lst || !new)
		return ;
	if (!head)
	{
		new->prev = NULL;
		new->next = NULL;
		*lst = new;
		return ;
	}
	new->next = head;
	new->prev = NULL;
	head->prev = new;
	*lst = new;
}
