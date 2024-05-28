#include "minishell.h"

int	main()
{
	t_parsing	parsing;

	parsing = (t_parsing){0};
	while (42)
	{
		parsing.input = readline("minishello >");
		if (parsing.input == NULL)
		{
			perror("Error on readline");
			continue ;
		}
		// parse_input(parsing.input);
	}
}

/* int main()
{
	char *s = "012345|7 0<<0 89\" a \'b\' c d \" has";
	char **mtx;
	int i = 0;

	mtx = create_mtx_from_input(s);
	printf("%s\n", s);
	while (mtx && mtx[i])
	{
		printf("%s\n", mtx[i]);
		i++;
	}
	free_mtx(mtx);
	return (0);
} */