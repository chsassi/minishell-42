#include "minishell.h"

int g_exit = 0;

int main(int ac, char **av, char **envp)
{
    t_env	*env = NULL;
	char	*input = NULL;
	char	*test = NULL;
	char	**mtx = NULL;
	int		*tokens = NULL;


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
		printf("Expnaded string: %s", test);
		mtx = create_mtx(test);
		if (!mtx)
			free(test);
		else
		{
			tokens = token_arr(mtx);
			write_mtx2(mtx, tokens);
			free(tokens);
			free_mtx(mtx);
			free(test);
		}
	}
	return (0);
}