/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:37:09 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(int nb, int power)
{
	int	n;

	n = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power == 1)
		return (nb);
	if (power > 1)
		n = n * ft_power(n, power - 1);
	return (n);
}

int	ft_atoi_base(char *str, char *base)
{
	int	n;
	int	q;
	int	r;
	int	j;

	n = 0;
	r = 0;
	j = strlen(str);
	while (str[r] != '\0')
	{
		q = 0;
		while (base[q])
		{
			if (str[r] == base[q])
				n = n + (q * ft_power(2, (j - r - 1)));
			q++;
		}
		r++;
	}
	return (n);
}

/* int	main()
{
	char	str[] = "00000010";
	char	base[] = "01";
	printf("%d", ft_atoi_base(str, base));
} */
