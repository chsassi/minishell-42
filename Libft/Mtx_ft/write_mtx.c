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

	i = 0;
	if (!mtx)
	{
		printf("mtx doesn't exist");
		return ;
	}
	while (mtx[i])
	{
		printf("%s\n", mtx[i]);
		i++;
	}
}
