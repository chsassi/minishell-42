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
	t_env *new_node;
	char *equal_sign;
	int equal_sign_pos;
	char *new_var;

	equal_sign = ft_strchr(env_var, '=');
	if (!equal_sign)
		return (NULL);
	equal_sign_pos = ft_strlen_until(env_var, '=');
	new_var = (char *)ft_calloc(equal_sign_pos + 1, sizeof(char));
	if (!new_var)
		return (NULL);
	ft_strlcpy(new_var, env_var, equal_sign_pos + 1);
	new_node = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new_node)
		return (free(new_var), NULL);
	new_node->var = new_var;
	set_var_content(new_node, equal_sign);
	new_node->next = NULL;
	return (new_node);
}

void	set_env_head(t_env **head, t_env *new_node, t_env **current)
{
	if (!(*head))
	{
		(*head) = new_node;
		(*current) = (*head);
	}
	else
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
