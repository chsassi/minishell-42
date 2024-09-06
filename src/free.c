#include "minishell.h"

void	free_env_node(t_env *node)
{
	if (node)
	{
		free(node->var);
		free(node->content);
		free(node);
		node->var = NULL;
		node->content = NULL;
	}
}
