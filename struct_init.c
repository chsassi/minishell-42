/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:18:08 by brulutaj          #+#    #+#             */
/*   Updated: 2024/07/16 17:07:10 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_all	*init_all(void)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		return (NULL);
	all->head = NULL;
	all->tail = NULL;
	all->size = 0;
	return (all);
}

t_elem	*create_elem(char *content, int len, enum e_token type)
{
	t_elem	*new_elem;

	new_elem = malloc(sizeof(t_elem));
	if (!new_elem)
		return (NULL);
	new_elem->content = malloc(len + 1);
	if (!new_elem->content)
	{
		free(new_elem);
		return (NULL);
	}
	ft_strlcpy(new_elem->content, content, len + 1);
	new_elem->len = len;
	new_elem->type = type;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}

void	add_token(t_all *all, t_elem *new_elem)
{
	if (!all || !new_elem)
		return ;
	if (all->head == NULL)
	{
		all->head = new_elem;
		all->tail = new_elem;
	}
	else
	{
		all->tail->next = new_elem;
		new_elem->prev = all->tail;
		all->tail = new_elem;
	}
	all->size++;
}
