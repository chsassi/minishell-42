/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:56:59 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/21 11:58:06 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (size_t)i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	char s1[] = "jokEr";
	char s2[] = "joker";
	printf("vero strncmp: %i\n", strncmp(s1, s2, 4));
	printf("mio strncmp: %i", ft_strncmp(s1, s2, 4));
	return(0);
}*/