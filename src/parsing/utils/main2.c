#include "minishell.h"

int main(int ac, char **av, char **envp)
{
    t_env	*env = create_envp(envp);
	char	*input = NULL;
	char	*test = NULL;


	(void)ac;
	(void)av;
	while (1)
	{
		input = readline("Minishell-> ");
		if (!input)
		{
			write (1, "exit\n", 5);
			break ;
		}
		if (!ft_strcmp(input, "env"))
			env = bin_env(env);
		test = expansion(input, env);
		printf("%s\n", test);
	}
	return (0);
}