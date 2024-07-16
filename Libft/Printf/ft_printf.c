/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:20:06 by brulutaj          #+#    #+#             */
/*   Updated: 2024/03/25 08:48:49 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_specifier(const char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar_printf(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr_printf(va_arg(ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_printf(va_arg(ap, int)));
	else if (c == 'p')
		return (ft_putaddr(va_arg(ap, uintptr_t)));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), c));
	else if (c == '%')
		return (ft_putchar_printf('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += ft_specifier(str[i + 1], ap);
			i++;
		}
		else
			len += ft_putchar_printf(str[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

/*
int main(void)
{
	printf("\n< %c >", 'a');
	ft_printf("I char: < %c > = ", 'a');
	
	char s[] = "ciao";
	printf("\n< %s >", s);
	ft_printf("Le stringhe: < %s > = ", s);

	printf("\n< %d >", 123);
	ft_printf("I numeri in d: < %d > = ", 123);

	printf("\n< %i >", 321);
	ft_printf("I numeri in i: < %i > = ", 321);

	int i = 42;
	printf("\n< %p >", &i);
	ft_printf("Indirizzo: < %p > = ", &i);

	printf("\n< %u >", 249585686);
	ft_printf("Numero unsigned: < %u > = ", 249585686);

	printf("\n< %x >", 6758594);
	ft_printf("Numero hexa low: < %x > = ", 6758594);

	printf("\n< %X >", 6758594);
	ft_printf("Numeri hexa upp: < %X > = ", 6758594);
	
	printf("\n< %% >");
	ft_printf("Segno percentuale: < %% > = ");
	return (0);
}*/