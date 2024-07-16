/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:27:31 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/21 11:55:36 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int main(void)
{
	printf("%d\n", ft_isprint(':'));
	printf("%d\n", ft_isprint(' '));
	printf("%d\n", ft_isprint('o'));
	printf("%d\n", ft_isprint(22));
	printf("%d", ft_isprint('\t'));
	return(0);
}*/
