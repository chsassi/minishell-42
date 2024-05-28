#include "minishell.h"

void	dll_input_set_index(t_dll_input **stack)
{
	t_dll_input	*tmp;
	int		    index;

	index = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->index = index;
		tmp = tmp->next;
		index++;
	}
}