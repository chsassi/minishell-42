#include "minishell.h"

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

	line = NULL;
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
		all_info = get_all_info(all_info, line, envp);
		while (all_info.cmd_line)
		{
			printf("[%s] is a %s\n --> merge: %d\n", all_info.cmd_line->content, enum_to_str(all_info.cmd_line->token), 
			all_info.cmd_line->merge);
			all_info.cmd_line = all_info.cmd_line->next;
		}
	}
}




/* 
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

int main()
{
	t_parsing parsing = (t_parsing){0};
	char *s = "chis sjs -s | d shd saakfj << kshf > dsh \" $s shk\" shf $dos";
	int i = 0;

	parsing.input = s;
	parsing = parse_input(parsing);
	if (parsing.size == 0)
		return (printf("error\n"), 0);
	while (i < parsing.size)
	{
		s = enum_to_str(parsing.arr_token[i]);
		printf("[%s] is a %s\n", parsing.mtx_from_input[i], s);
		free(s);
		i++;
	}
	free_mtx(parsing.mtx_from_input);
	free(parsing.arr_token);
	return (0);
}
 */