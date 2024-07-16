/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_set_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:21:52 by brulutaj          #+#    #+#             */
/*   Updated: 2024/04/24 16:22:17 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_index(t_dll **stack)
{
	t_dll	*tmp;
	int		index;

	index = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->index = index;
		tmp = tmp->next;
		index++;
	}
}
