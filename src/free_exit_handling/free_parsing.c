#include "minishell.h"

void	free_parsing(t_parsing *parsing)
{
	free(parsing->arr_token);
	free_mtx(parsing->mtx_from_input);
}

//free per t_builtin da definire

void	set_clear_all(t_all *all)
{
	dll_input_clear(&(all->cmd_line));
}

void	free_all(t_all *all)
{
	ft_lstclear(&(all->envp), free);
	dll_input_clear(&(all->cmd_line));
	//free_builtin(all->ptr);
}

void	close_all(t_all *all)
{
	free_all(all);
	exit(0);
}