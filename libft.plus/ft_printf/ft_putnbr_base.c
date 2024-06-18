/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:08:28 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long nbr, char *base, int *length)
{
	int	base_len;

	base_len = xstrlen(base);
	if (nbr < 0)
	{
		ft_putchar('-', length);
		nbr = -nbr;
	}
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base, length);
	if ((nbr % base_len) < 10)
		ft_putchar((nbr % base_len) + '0', length);
	else
		ft_putchar(base[nbr % base_len], length);
}

/* int	main(void)
{
	int length = 0;
	ft_putnbr_base(15, BASE16, &length);
} */
