#include "minishell.h"

int g_exit = 0;

// static void write_arr_merge(int *arr, char **mtx)
// {
// 	int i = 0;

// 	while(mtx[i] != NULL)
// 	{
// 		if (arr[i] == NEXT)
// 			printf("[NEXT] [%s]\n", mtx[i]);
// 		else if (arr[i] == PREV)
// 			printf("[PREV] [%s]\n", mtx[i]);
// 		else if (arr[i] == BOTH)
// 			printf("[BOTH] [%s]\n", mtx[i]);
// 		else
// 			printf("[NO] [%s]\n", mtx[i]);
// 		i++;
// 	}
// }

static void		write_parse(t_pars *head)
{
	while (head)
	{
		printf("[strig %s ]__[int %i]\n", head->str, head->type);
		head = head->next;
	}
}

int main(int ac, char **av, char **envp)
{
    t_env	*env = NULL;
	char	*input = NULL;
	char	**mtx = NULL;
	int		*tokens = NULL;
	t_pars	*parser = NULL;	
	// int		*mergers = NULL;
	// int		*pro_mergers = NULL;


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
		// input = trimmed_quote_token(input);
		// printf("String trimmed: [ %s ]\n", input);
		// free(input);
		if (!ft_strcmp(input, "env"))
			env = bin_env(env);
		input = expansion(input, env);
		printf("Expanded string: %s\n", input);
		mtx = create_mtx(input);
		if (!mtx)
			return(free(input), 0);
		else
		{
			tokens = token_arr(mtx);
			parser = parse_struct_init(input, mtx, tokens);
		// 	mergers = array_of_merges(input, mtx);
		// 	pro_mergers = process_arr_merger(input, mtx);
			// write_arr_merge(mergers, mtx);
			//printf("\n");
			// write_arr_merge(pro_mergers, mtx);
			//write_mtx2(mtx, tokens);
			write_parse(parser);
			// free(mergers);
			// free(pro_mergers);
			clear_parse(parser);
			free(tokens);
			free(input);
		}
	}
	return (0);
}