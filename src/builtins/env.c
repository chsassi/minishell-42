/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:17:57 by chsassi           #+#    #+#             */
/*   Updated: 2024/08/19 16:39:51 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (!new_node->content)
		return (free(new_var), free(new_node), NULL);
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

void	bin_env(char **envp/* t_all *pAll */)
{
	t_env	*current_env;

	// if (/* pAll->prompt[1] */)
	// {
	// 	printf("env: '%s': No such file or directory\n", mtx[1]/* pAll->prompt[1] */);
	// 	return ;
	// }
	// else
	current_env = create_envp(envp);
	while (current_env)
	{
		printf("%s=%s\n", current_env->var, current_env->content);
		current_env = current_env->next;
	}
}
