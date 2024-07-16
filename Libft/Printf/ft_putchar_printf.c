/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:54:19 by brulutaj          #+#    #+#             */
/*   Updated: 2024/03/25 08:49:07 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_printf(int c)
{
	write(1, &c, 1);
	return (1);
}
/*
int	main(void)
{
	int	i = 0;
	ft_putchar('g', &i);
	printf("\n%i", i);
}*/