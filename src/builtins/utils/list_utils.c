/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:33:15 by chsassi           #+#    #+#             */
/*   Updated: 2024/09/25 10:41:06 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_var_content(t_env *new_node, char *equal_sign)
{
	if (equal_sign)
	{
		new_node->content = ft_strdup(equal_sign + 1);
		new_node->is_hidden = false;
	}
	else
	{
		new_node->content = NULL;
		new_node->is_hidden = true;
	}
}

t_env	*new_env_node(char *env_var)
{
	t_env	*new_node;
	char	*equal_sign;
	int		var_len;

	var_len = 0;
	equal_sign = ft_strchr(env_var, '=');
	if (equal_sign)
		var_len = ft_strlen_until(env_var, '=');
	else
		var_len = ft_strlen(env_var);
	new_node = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->var = (char *)ft_calloc(var_len + 1, sizeof(char));
	if (!new_node->var)
		return (free(new_node), NULL);
	ft_strlcpy(new_node->var, env_var, var_len + 1);
	set_var_content(new_node, equal_sign);
	return (new_node);
}

void	set_env_head(t_env **head, t_env *new_node, t_env **current)
{
	if (!(*head))
	{
		(*head) = new_node;
		if (current)
			(*current) = (*head);
	}
	else if (current)
	{
		(*current)->next = new_node;
		(*current) = new_node;
	}
}

t_env	*create_envp(char **envp)
{
	t_env	*head;
	t_env	*current;
	t_env	*new_node;
	int		rows;

	rows = 0;
	head = NULL;
	current = NULL;
	new_node = NULL;
	while (envp[rows])
	{
		new_node = new_env_node(envp[rows]);
		if (!new_node)
			return (free_env_list(head), NULL);
		set_env_head(&head, new_node, &current);
		rows++;
	}
	return (head);
}
