#include "minishell.h"

void	pwd(void)
{
	char *directory;

	directory = getcwd(NULL, 0);
	if (!directory)
	{
		ft_printf("error: directory not found or not set");
		return ;
	}
	else
		ft_printf("%s", directory);
	free(directory);
}
