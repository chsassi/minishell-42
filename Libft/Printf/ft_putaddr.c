/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:34:10 by brulutaj          #+#    #+#             */
/*   Updated: 2024/03/25 08:48:58 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_chchar(int c)
{
	write(1, &c, 1);
}

static int	len_ptr(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

static void	ft_ptoadd(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_ptoadd(ptr / 16);
		ft_ptoadd(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_chchar(ptr + 48);
		else
			ft_chchar(ptr - 10 + 'a');
	}
}

int	ft_putaddr(uintptr_t ptr)
{
	int	len;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len = 2;
	ft_ptoadd(ptr);
	len += len_ptr(ptr);
	return (len);
}
/*
int main(void)
{
	int i = 42;
	int res = ft_putaddr((uintptr_t)&i);
	printf("\n%p\n", (void *)&i);
	printf("%d", res);
	return (0);
}*/