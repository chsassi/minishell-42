/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:35:45 by brulutaj          #+#    #+#             */
/*   Updated: 2024/04/24 16:26:18 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dll_add_back(t_dll **lst, t_dll *new)
{
	t_dll	*last;
	int		index;

	if (!lst || !new)
		return ;
	index = dll_size(*lst);
	last = dll_last(*lst);
	if (!(*lst))
	{
		new->prev = NULL;
		new->next = NULL;
		new->index = 0;
		*lst = new;
		return ;
	}
	new->prev = last;
	new->next = NULL;
	new->index = index;
	last->next = new;
}
