#include "minishell.h"

int run_exec(t_all *pAll)
{
    if (!ft_strcmp(pAll->node->content, "echo"))
        return (run_echo(pAll));
    else if (!ft_strcmp(pAll->node->content, "cd"))
        return (run_cd());
    else if (!ft_strcmp(pAll->node->content, "pwd"))
        return (run_pwd());
    else if (!ft_strcmp(pAll->node->content, "export"))
        return (run_export());
    else if (!ft_strcmp(pAll->node->content, "unset"))
        return (run_unset());
    else if (!ft_strcmp(pAll->node->content, "env"))
        return (run_env());
    else if (!ft_strcmp(pAll->node->content, "exit"))
        return (run_exit());
    else
        return (0);
}