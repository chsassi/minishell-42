/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:40:44 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/21 11:57:58 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s2)
		return (NULL);
	while (s[i])
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
/*
static char	ft_toupper2(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int main (void)
{
	char s[] = "rogorit";
	char *even_upped = ft_strmapi(s, ft_toupper2);
	printf("%s", even_upped);
	free (even_upped);
	return(0);
}*/