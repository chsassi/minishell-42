#include "minishell.h"

char    **parsing_list_in_mtx(t_input *cmd_line)
{
    char    **mtx_input;
    int     size;
    int     i;
    
    size = dll_input_size(cmd_line);
    i = 0;
    mtx_input = ft_calloc(size + 1, sizeof(char *));
    if (!mtx_input)
        return (NULL);
    while (cmd_line && i < size)
    {
        mtx_input[i] = ft_strdup(cmd_line->content);
        if (!mtx_input[i])
            return (free_mtx(mtx_input), NULL);
        i++;
        cmd_line = cmd_line->next;
    }
    return (mtx_input);
}