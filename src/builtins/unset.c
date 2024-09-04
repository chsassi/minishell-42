/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:17:57 by chsassi           #+#    #+#             */
/*   Updated: 2024/07/30 10:19:00 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*bin_unset(t_env **head, char *var_name)
{
	t_env	*tmp;
	t_env	**original_head;

	if (!head || !*head)
		return (*head);
	original_head = head;
	while (*head && ft_strcmp((*head)->var, var_name))
		head = &((*head)->next);
	if (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free_env_node(tmp);
	}
	return (*original_head);
}
