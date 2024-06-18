/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:05:40 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**mtx_alloc(int rows, int cols)
{
	int		i;
	char	**mtx;

	i = 0;
	mtx = ft_calloc(rows, sizeof(char *));
	if (!mtx)
		ft_printf("Error during row allocation.\n");
	while (i < rows)
	{
		mtx[i] = ft_calloc(cols, sizeof(char));
		if (!mtx[i])
			ft_printf("Error during col allocation.\n");
		i++;
	}
	return (mtx);
}

char	**copy_mtx(char **mtx)
{
	int		i;
	char	**mtx_cpy;

	i = 0;
	if (!mtx)
		return (NULL);
	mtx_cpy = ft_calloc((count_rows(mtx) + 1), sizeof(char *));
	if (!mtx_cpy)
		return (NULL);
	while (mtx[i])
	{
		mtx_cpy[i] = ft_strdup(mtx[i]);
		if (!mtx_cpy[i])
			return (free_mtx(mtx_cpy), NULL);
		i++;
	}
	return (mtx_cpy);
}

void	free_mtx(char **mtx)
{
	int	i;
	int	len;

	if (!mtx)
		return ;
	len = count_rows(mtx);
	i = 0;
	while (i < len)
	{
		free(mtx[i]);
		mtx[i] = NULL;
		i++;
	}
	free(mtx);
}
