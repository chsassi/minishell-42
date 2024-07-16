/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_add_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:13:45 by brulutaj          #+#    #+#             */
/*   Updated: 2024/04/30 18:42:34 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dll_add_front(t_dll **lst, t_dll *new)
{
	t_dll	*head;

	head = *lst;
	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		new->prev = NULL;
		new->next = NULL;
		new->index = 0;
		*lst = new;
		return ;
	}
	new->next = head;
	new->prev = NULL;
	new->index = 0;
	head->prev = new;
	*lst = new;
	set_index(lst);
}
