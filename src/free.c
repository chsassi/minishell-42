#include "minishell.h"

void	free_env_node(t_env *node)
{
	if (node)
	{
		free(node->var);
		free(node->content);
		node->var = NULL;
		node->content = NULL;
		free(node);
	}
}
