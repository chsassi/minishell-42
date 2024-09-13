#include "minishell.h"

t_env	*new_env_node(const char *env_var)
{
	t_env	*new_node;
	char	*equal_sign;
	int		equal_sign_pos;
	char	*new_var;

	equal_sign = ft_strchr(env_var, '=');
	if (!equal_sign)
		return (NULL);
	equal_sign_pos = ft_strlen_until((char *)env_var, '=');
	new_var = (char *)ft_calloc(equal_sign_pos + 1, sizeof(char));
	ft_strlcpy(new_var, env_var, equal_sign_pos + 1);
	new_node = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new_node)
		return (free(new_var), NULL);
	new_node->var = new_var;
	new_node->content = ft_strdup(equal_sign + 1);
	if (!ft_strchr(env_var, '='))
		new_node->is_hidden = true;
	else
		new_node->is_hidden = false;
	new_node->next = NULL;
	return (new_node);
}

t_env	*create_envp(char **envp)
{
	t_env	*head = NULL;
	t_env	*current = NULL;
	t_env	*new_node;
	int		rows;

	rows = 0;
	while (envp[rows])
	{
		new_node = new_env_node(envp[rows]);
		if (!new_node)
			return (free(new_node), NULL);
		if (!head)
		{
			head = new_node;
			current = head;
		}
		else
		{
			current->next = new_node;
			current = new_node;
		}
		new_node = new_node->next;
		rows++;
	}
	return (head);
}
