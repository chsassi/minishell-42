/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:30:44 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>

static int	count_figures(long nb)
{
	int		figures;

	figures = 1;
	if (nb < 0)
	{
		nb = -nb;
		figures++;
	}
	while (nb > 9)
	{
		nb /= 10;
		figures++;
	}
	return (figures);
}

char	*ft_itoa(int nb)
{
	long	n;
	int		i;
	char	*res;

	n = nb;
	i = count_figures(n);
	res = (char *)malloc(i + 1);
	if (!res)
		return (NULL);
	res[i--] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		res[i--] = '0' + (n % 10);
		n /= 10;
	}
	if (nb == 0)
		res[0] = '0';
	return (res);
}

/*int	main()
{
	char * res = itoa(2147483648);
	printf("%s", res);
}*/
