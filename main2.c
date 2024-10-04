#include "minishell.h"

int g_exit = 0;

static void write_arr_merge(int *arr, char **mtx)
{
	int i = 0;

	while(mtx[i] != NULL)
	{
		if (arr[i] == NEXT)
			printf("[NEXT] [%s]\n", mtx[i]);
		else if (arr[i] == PREV)
			printf("[PREV] [%s]\n", mtx[i]);
		else if (arr[i] == BOTH)
			printf("[BOTH] [%s]\n", mtx[i]);
		else
			printf("[NO] [%s]\n", mtx[i]);
		i++;
	}
}

int main(int ac, char **av, char **envp)
{
    t_env	*env = NULL;
	char	*input = NULL;
	char	*test = NULL;
	char	**mtx = NULL;
	//int		*tokens = NULL;
	int		*mergers = NULL;
	int		*pro_mergers = NULL;


	(void)ac;
	(void)av;
	env = create_envp(envp);
	while (1)
	{
		input = readline("Minishell-> ");
		if (!input)
		{
			write(1, "exit\n", 5);
			free_env_list(env);
			break ;
		}
		if (!ft_strcmp(input, "env"))
			env = bin_env(env);
		test = expansion(input, env);
		printf("Expanded string: %s\n", test);
		mtx = create_mtx(test);
		if (!mtx)
			free(test);
		else
		{
			mergers = array_of_merges(input, mtx);
			pro_mergers = process_arr_merger(input, mtx);
			write_arr_merge(mergers, mtx);
			printf("\n");
			write_arr_merge(pro_mergers, mtx);
			//tokens = token_arr(mtx);
			// write_mtx2(mtx, tokens);
			free(mergers);
			free_mtx(mtx);
			free(test);
		}
	}
	return (0);
}