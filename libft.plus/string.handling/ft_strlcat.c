/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:45:52 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	if (ft_strlen(dst) >= size)
		return (ft_strlen(src) + size);
	res = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}

/*int	main() {
	const char	str1[] = "Hello, ";
	char		dest[20] = "Hello, ";
	const char	src[] = "world!";
	size_t		result_len = ft_strlcat(dest, src, sizeof(dest));

	printf("Dopo la concatenazione: %s\n", dest);
	printf("La lunghezza totale dopo la concatenazione è %zu\n", result_len);
}*/
