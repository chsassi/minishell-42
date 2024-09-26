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

void	free_env_var(char *var, char *content)
{
	free(var);
	free(content);
	var = NULL;
	content = NULL;
}

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

void	free_env_list(t_env *head)
{
	t_env *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free_env_node(tmp);
	}
}