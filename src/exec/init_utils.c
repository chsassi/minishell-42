#include "minishell.h"

void	input_check(t_all *pAll)
{
	if (!pAll->input)
	{
		write(1, "exit\n", 6);
		free_all(pAll, true, pAll->status_code);
	}
}

void	close_pipes_loop(t_all *pAll)
{
	int	i;

	i = 0;
	while (i < pAll->cmd_nbr - 1)
	{
		close(pAll->arr_pipe[i][0]);
		close(pAll->arr_pipe[i][1]);
		free(pAll->arr_pipe[i]);
		i++;
	}
	free(pAll->arr_pipe);
	pAll->arr_pipe = NULL;
}
