#include "minishell.h"

void	dll_input_clear(t_input **lst)
{
	t_input	*ptr;

	while (lst && *lst)
	{
		ptr = (*lst)->next;
		free((*lst)->content);
		free_mtx((*lst)->args);
		free(*lst);
		*lst = ptr;
	}
	*lst = NULL;
}
