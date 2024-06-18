#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_all		all_info;
	char		*line;

	line = NULL;
	all_info = (t_all){0};
	(void)ac;
	(void)av;
	while (42)
	{
		line = readline("minishello > ");
		if (line == NULL)
		{
			// perror("Error on readline");
			//error for ctrl-D
			continue ;
		}
		all_info = get_input_complete(all_info, line, envp);
		//gestione errori durante la get_input_complete da fare
		if (!all_info.cmd_line)
			continue ;
		// esecuzione
		set_clear_all(&all_info);
	}
	return (0);
}


/* 
// testing parsing
char *enum_to_str(int enume)
{
	if (enume == CMD)
		return (ft_strdup("command"));
	else if (enume == ARG)
		return (ft_strdup("argument"));
	else if (enume == FILE_W)
		return (ft_strdup("file"));
	else if (enume == EOF_DEL)
		return (ft_strdup("heredoc_del"));
	else if (enume == WORDS)
		return (ft_strdup("word"));
	else if (enume == DOLLAR_SIGN)
		return (ft_strdup("dollar sign"));
	else if (enume == PIPE)
		return (ft_strdup("pipe"));
	else if (enume == R_INPUT)
		return (ft_strdup("red. input"));
	else if (enume == R_OUTPUT)
		return (ft_strdup("red. output"));
	else if (enume == D_RED_INPUT)
		return (ft_strdup("d. red. input"));
	else if (enume == D_RED_OUTPUT)
		return (ft_strdup("d. red. output"));
	else if (enume == D_QUOTE)
		return (ft_strdup("double quote"));
	else if (enume == S_QUOTE)
		return (ft_strdup("single quote"));
	return (NULL);
}

int	main(int ac, char **av, char **envp)
{
	t_all		all_info;
	char		*line;
	int			i;

	line = NULL;
	i = 0;
	all_info = (t_all){0};
	(void)ac;
	(void)av;
	while (42)
	{
		line = readline("minishello > ");
		if (line == NULL)
		{
			perror("Error on readline");
			continue ;
		}
		all_info = get_input_complete(all_info, line, envp);
		while (all_info.cmd_line)
		{
			printf("[%s] is a %s\n", all_info.cmd_line->content, enum_to_str(all_info.cmd_line->token));
			i = 0;
			while (all_info.cmd_line->args && all_info.cmd_line->args[i])
			{
				printf("arg[%d]: %s\n", i, all_info.cmd_line->args[i]);
				i++;
			}
			all_info.cmd_line = all_info.cmd_line->next;
		}
	}
	return (0);
} */