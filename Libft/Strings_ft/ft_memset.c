/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:18:16 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/21 11:56:53 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*str, int c, size_t n)
{
	char	*string;
	size_t	i;

	i = 0;
	string = (char *)str;
	while (i < n)
	{
		string[i] = c;
		i++;
	}
	return (str);
}
/*
int main(void)
{
	char s[] = "p";
	int c;
	size_t n;
	c = 'h';
	n = 5;
	printf("%s\n", s);
	memset(s + 6, c, n);
	ft_memset(s + 6, c, n);
	printf("%s", s);
	return(0);
}*/
