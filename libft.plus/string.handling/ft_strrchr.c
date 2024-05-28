/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:47:47 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/28 18:01:33 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	len;

	len = ft_strlen(s) + 1;
	if (!s)
		return (NULL);
	while (len > 0)
	{
		len--;
		if (s[len] == (unsigned char)c)
			return ((char *)&s[len]);
	}
	return (NULL);
}

/* int main(void)
{
	const char	*string = "Hello, World!";
	int			character = 'l';

	char		*result = ft_strrchr(string, character);
	printf("Strrchr:		%s", result);
} */
