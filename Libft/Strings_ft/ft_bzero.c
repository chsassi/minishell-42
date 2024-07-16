/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:01:39 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/21 11:54:44 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}
/*
int main(void)
{
	char s[] = "wrtdgdffu";
	size_t n;
	n = 3;
	printf("%s\n", s);
	//bzero(s + 3, n);
	ft_bzero(s + 3, n);
	printf("%s", s);
	return(0);
}*/
