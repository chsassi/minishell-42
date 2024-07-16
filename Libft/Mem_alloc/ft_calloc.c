/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:41:56 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/21 11:54:53 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
/*
int main(void)
{
	char 	*a;
	size_t	nmemb = 5;
	size_t	size = sizeof(char);
	size_t	i;
	i = 0;
	a = ft_calloc(nmemb + 1, size);
	while (i < nmemb)
	{
		a[i] = 'a';
		write(1, &a[i], 1);
		i++;
	}
	a[i] = '\0';
	free (a);
	return(0);
}*/