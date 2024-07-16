/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:18:08 by brulutaj          #+#    #+#             */
/*   Updated: 2024/07/15 12:21:53 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_all	*init_all(void)
{
	t_all	*all;
	
	all = (t_all *)malloc(sizeof(t_all));
	if(!all)
		return (NULL);
	all->head = NULL;
	all->tail = NULL;
	all->size = 0;
	return (all);
}