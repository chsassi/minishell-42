#include "minishell.h"

char *arr_int_str(int i)
{
    if (i == WORD)
        return(ft_strdup("WORD"));
    else if(i == QUOTE)
        return(ft_strdup("QUOTE"));
    else if(i == DOUBLE_QUOTE)
        return(ft_strdup("DOUBLE_QUOTE"));
    else if (i == PIPE_LINE)
        return(ft_strdup("PIPE_LINE"));
    else if (i == REDIR_IN)
        return(ft_strdup("REDIR_IN"));
    else if (i == REDIR_OUT)
        return(ft_strdup("REDIR_OUT"));
    else if (i == HERE_DOC)
        return(ft_strdup("HERE_DOC"));
    else
        return(ft_strdup("DREDIR_OUT"));
    return(ft_strdup(""));
}

void	write_mtx2(char **mtx, int *arr)
{
	int	i;
    char *s = NULL;

	i = 0;
	if (!mtx)
	{
		printf("mtx doesn't exist");
		return ;
	}
	while (mtx[i])
	{
        s = arr_int_str(arr[i]);
		printf("[ %s ]__[ %s ]\n", mtx[i], s);
        free(s);
		i++;
	}
}
