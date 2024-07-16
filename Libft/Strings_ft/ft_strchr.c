/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:43:18 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/21 11:57:09 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	len_str;
	char	*str2;

	len_str = ft_strlen(str);
	str2 = (char *)str;
	i = 0;
	while (i <= len_str)
	{
		if (str2[i] == (char)c)
			return (&str2[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *s = "magnifica";
	int c = 'f';
	printf("%s\n", ft_strchr(s, c));
	printf("%s", strchr(s, c));
	return(0);
}*/
