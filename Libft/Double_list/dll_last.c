/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:02:21 by brulutaj          #+#    #+#             */
/*   Updated: 2024/04/24 16:17:02 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dll	*dll_last(t_dll *lst)
{
	t_dll	*new;

	if (!lst)
		return (NULL);
	new = lst;
	while (new->next != NULL)
		new = new->next;
	return (new);
}
