/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:45:11 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/21 11:58:35 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
int main(void)
{
	printf("%c\n", ft_tolower('F'));
	printf("%c\n", ft_tolower('h'));
	printf("%c", ft_tolower('7'));
	return(0);
}*/
