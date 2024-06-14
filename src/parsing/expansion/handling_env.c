#include "minishell.h"

int	find_len_env(t_list *envp, char *name_env)
{
	t_list	*tmp;
	char	*content;
	int		len;

	tmp = envp;
	content = NULL;
	len = ft_strlen(name_env);
	while (tmp)
	{
		content = (char *)tmp->content;
		if (!ft_strncmp(content, name_env, len))
			return (ft_strlen(content) - (len + 1));
		tmp = tmp->next;
	}
	return (-1);
}

char	*find_expansion_env(t_list *envp, char *name_env)
{
	t_list	*tmp;
	char	*content;
	int		len;

	tmp = envp;
	content = NULL;
	len = ft_strlen(name_env) + 1;
	while (tmp)
	{
		content = (char *)tmp->content;
		if (!ft_strncmp(content, name_env, len - 1))
			return (&content[len]);
		tmp = tmp->next;
	}
	return (ft_strdup(""));
}