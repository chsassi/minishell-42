/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:54:01 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		*res;
	size_t		len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (unsigned char)c)
		{
			res = (char *)&s[i];
			return (res);
		}
		i++;
	}
	return (NULL);
}

/* int main(void)
{
	const char	*string = "Hello, World!";
	int			character = 'o';

	char		*result = ft_strchr(string, character);
	printf("Strchr:		%s", result);
} */
