/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:35:20 by brulutaj          #+#    #+#             */
/*   Updated: 2024/03/25 08:49:14 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_chchar(int c)
{
	write(1, &c, 1);
}

static int	len_ptr(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void	write_hex(unsigned int n, const char type)
{
	if (n >= 16)
	{
		write_hex(n / 16, type);
		write_hex(n % 16, type);
	}
	else
	{
		if (n <= 9)
			ft_chchar(n + 48);
		else
		{
			if (type == 'x')
				ft_chchar(n - 10 + 'a');
			else if (type == 'X')
				ft_chchar(n - 10 + 'A');
		}
	}
}

int	ft_puthex(unsigned int n, const char type)
{
	int	len;

	len = len_ptr(n);
	if (!n)
	{
		ft_chchar('0');
		return (1);
	}
	else
		write_hex(n, type);
	return (len);
}
/*
int main (void)
{
	int len = ft_puthex(301, 'x');
	printf("\n%d", len);
}*/
