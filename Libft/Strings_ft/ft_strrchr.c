/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:54:27 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/21 11:58:23 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*str2;

	i = ft_strlen(str) + 1;
	str2 = (char *)str;
	while (i-- > 0)
	{
		if (str2[i] == (unsigned char)c)
			return (&str2[i]);
	}
	return (NULL);
}
/*
int main(void)
{
	const char s[] = "fortifica";
	int c = 'f';
	printf("%s", ft_strrchr(s, c));
	printf("%s", strrchr(s, c));
	return(0);
}*/
