/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mtx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:52:14 by brulutaj          #+#    #+#             */
/*   Updated: 2024/08/21 11:32:41 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_mtx(char **mtx)
{
	int	j;

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
