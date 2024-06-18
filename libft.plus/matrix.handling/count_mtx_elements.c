/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_mtx_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:04:33 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_cols(char **mtx)
{
	int	cols;

	cols = 0;
	while (mtx && mtx[0][cols])
		cols++;
	return (cols);
}

int	count_rows(char **mtx)
{
	int	rows;

	rows = 0;
	while (mtx && mtx[rows] != NULL)
		rows++;
	return (rows);
}

int	count_elements(char **mtx, char c)
{
	int	rows;
	int	cols;
	int	element_nbr;

	rows = -1;
	element_nbr = 0;
	while (mtx[++rows] != NULL)
	{
		cols = -1;
		while (mtx[rows][++cols] != '\0')
		{
			if (mtx[rows][cols] == c)
				element_nbr++;
		}
	}
	return (element_nbr);
}
