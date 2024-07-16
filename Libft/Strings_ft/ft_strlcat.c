/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:44:19 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/21 11:57:23 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	j = dst_len;
	if (size == 0)
		return (src_len);
	else if (size < dst_len)
		return (size + src_len);
	else
	{
		while (j < size - 1 && src[i] != '\0')
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = '\0';
	}
	return (dst_len + src_len);
}
/*
int main (void)
{
	char s[]= "ddd";
	char d[]= "rrrrrrrrrr";
	printf("%s\n", d);
	printf("%zu\n", ft_strlcat(d, s, 2));
	printf("%s", d);
	return(0);
}*/