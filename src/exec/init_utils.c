#include "minishell.h"

int	input_check(t_all *pAll)
{
	if (!pAll->shell->input)
	{
		write(1, "exit\n", 6);
		free_env_list(*pAll->env);
		exit(pAll->status_code);
		return (0);
	}

	return (1);
}

void	close_pipes_loop(int **pipex, int cmd_nbr)
{
	int	i;

	i = 0;
	while (i < cmd_nbr - 1)
	{
		close(pipex[i][0]);
		close(pipex[i][1]);
		free(pipex[i]);
		i++;
	}
	free(pipex);
}
