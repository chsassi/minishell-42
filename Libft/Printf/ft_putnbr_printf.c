/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:40:27 by brulutaj          #+#    #+#             */
/*   Updated: 2024/03/25 08:49:23 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cifre(long n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa_printf(int n)
{
	char	*str;
	int		len;
	long	nl;

	len = cifre(n);
	nl = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nl == 0)
		str[0] = 48;
	str[len] = '\0';
	if (nl < 0)
	{
		str[0] = '-';
		nl = -nl;
	}
	len -= 1;
	while (nl != 0)
	{
		str[len] = nl % 10 + 48;
		nl = nl / 10;
		len--;
	}
	return (str);
}

int	ft_putnbr_printf(int n)
{
	int		len;
	char	*num;

	num = ft_itoa_printf(n);
	len = ft_putstr_printf(num);
	free (num);
	return (len);
}
/*
int main(void)
{
	int len = ft_putnbr(-797678);
	printf("\n%d", len);
}*/