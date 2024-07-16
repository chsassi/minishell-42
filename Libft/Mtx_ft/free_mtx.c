/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mtx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:52:14 by brulutaj          #+#    #+#             */
/*   Updated: 2024/04/10 18:24:39 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_mtx(char **mtx)
{
	size_t	j;

	j = 0;
	if (!mtx)
		return ;
	while (mtx[j])
	{
		free(mtx[j]);
		mtx[j] = NULL;
		j++;
	}
	free(mtx);
	mtx = NULL;
}
