#include "minishell.h"

int main(int ac, char **av, char **envp)
{
    // t_env	*env = create_envp(envp);
	char	*input = NULL;
	char	*test = NULL;


	(void)ac;
	(void)av;
	(void)envp;
	while (1)
	{
		input = readline("Minishell-> ");
		if (!input)
		{
			write(1, "exit\n", 5);
			break ;
		}
		// if (!ft_strcmp(input, "env"))
		// 	env = bin_env(env);
		test = processed_str_exp(input);
		printf("%s\n", test);
		free(test);
	}
	return (0);
}