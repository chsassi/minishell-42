/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:03:15 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/21 11:55:21 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_isascii('5'));
	printf("%d\n", ft_isascii(0));
	printf("%d\n", ft_isascii(1300));
	printf("%d", ft_isascii(127));
	return(0);
}*/
