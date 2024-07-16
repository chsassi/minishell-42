/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_mtx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:27:53 by brulutaj          #+#    #+#             */
/*   Updated: 2024/04/11 09:39:30 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_mtx(char **mtx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!mtx)
	{
		ft_printf("mtx doesn't exist");
		return ;
	}
	while (mtx[i])
	{
		ft_printf("[%d] %s\n", j, mtx[i]);
		i++;
		j++;
	}
}
