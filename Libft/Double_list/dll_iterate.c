/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_iterate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:18:13 by brulutaj          #+#    #+#             */
/*   Updated: 2024/04/24 16:19:38 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dll	*dll_iterate(t_dll *lst)
{
	t_dll	*new;

	if (!lst)
		return (NULL);
	new = lst;
	while (new->next != NULL)
		new = new->next;
	return (new);
}
