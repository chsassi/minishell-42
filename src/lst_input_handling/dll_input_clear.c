#include "minishell.h"

void	dll_input_clear(t_dll_input **lst)
{
	t_dll_input	*ptr;

	while (lst && *lst)
	{
		ptr = (*lst)->next;
        free((*lst)->content);
        free((*lst)->path);
		free(*lst);
		*lst = ptr;
	}
	*lst = NULL;
}