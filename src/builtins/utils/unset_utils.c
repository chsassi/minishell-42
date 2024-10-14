#include "minishell.h"

bool	unset_check_head(t_all *pAll, char *variable)
{
	t_env	*tmp;

	if (!pAll->env)
		return (true);
	if ((*pAll->env)->var && !ft_strcmp((*pAll->env)->var, variable))
	{
		tmp = *pAll->env;
		*pAll->env = (*pAll->env)->next;
		free_env_node(tmp);
	}
	return (true);
}

bool	unset_check_all(t_all *pAll, char *variable)
{
	t_env	*tmp;
	t_env	*next;

	tmp = *pAll->env;
	while (tmp && tmp->next)
	{
		next = tmp->next;
		if (next && !ft_strcmp(next->var, variable))
		{
			tmp->next = next->next;
			free_env_node(next);
		}
		tmp = tmp->next;
	}
	return (true);
}
