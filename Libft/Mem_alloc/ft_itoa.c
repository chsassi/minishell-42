/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:22:15 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/13 11:41:42 by brulutaj         ###   ########.fr       */
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

char	*ft_itoa(int n)
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
/*
int main(void)
{
	char *zero = ft_itoa(0);
	char *max = ft_itoa(2147483647);
	char *min = ft_itoa(-2147483648);
	printf("%s\n", zero);
	printf("%s\n", max);
	printf("%s", min);
	free (zero);
	free (max);
	free (min);
	return (0);
}*/