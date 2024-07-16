/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_mtx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:59:05 by brulutaj          #+#    #+#             */
/*   Updated: 2024/04/11 12:53:51 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**copy_mtx(char **mtx)
{
	char	**mtx2;
	int		i;

	mtx2 = ft_calloc(ft_rowlen(mtx) + 1, sizeof(char *));
	if (!mtx2)
		return (NULL);
	i = 0;
	while (mtx && mtx[i])
	{
		mtx2[i] = ft_strdup(mtx[i]);
		if (!mtx2[i])
			return (free(mtx2), NULL);
		i++;
	}
	return (mtx2);
}
