/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:06:44 by chsassi           #+#    #+#             */
/*   Updated: 2024/08/25 16:02:26 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "libft.h"

t_env	*env_new_node(char *var, char *content)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->var = ft_strdup(var);
	new->content = ft_strdup(content);
	new->next = NULL;
	return (new);
}

t_env	*env_last(t_env *list)
{
	if (!list)
		return (NULL);
	while (list)
	{
		if (list->next == NULL)
			return (list);
		list = list->next;
	}
	return (list);
}

void	env_lstadd_back(t_env **head, t_env *new)
{
	t_env	*tmp;

	tmp = NULL;
	if (!head || !new)
		return ;
	if (!(*head))
	{
		*head = new;
		return ;
	}
	tmp = env_last(*head);
	tmp->next = new;
}

void	free_env_var(char *var, char *content)
{
	free(var);
	free(content);
	var = NULL;
	content = NULL;
}
