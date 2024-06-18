/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:35:54 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*res;
	unsigned char			occ;

	i = 0;
	res = (const unsigned char *)s;
	occ = (unsigned char)c;
	while (i < n)
	{
		if (res[i] == occ)
			return ((void *)(res + i));
		i++;
	}
	return (NULL);
}

/* int		main(void)
{
	char	*str = "Casa mia";
	char	c = 'm';
	size_t	n = 6;

	str = ft_memchr(str, c, n);
	printf("Memchr:		%s", str);
} */
