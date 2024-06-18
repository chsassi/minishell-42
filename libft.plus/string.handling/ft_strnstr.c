/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:15:32 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && len > 0)
	{
		if (ft_strncmp(&big[i], little, little_len) == 0 && len >= little_len)
			return ((char *)&big[i]);
		i++;
		len--;
	}
	return (NULL);
}

/*int		main(void)
{
	char	str[] = "Ciao come stai?";
	char	str2[] = "come";
	int		i = 0;
	int		len = ft_strlen(str);
	char	*res = ft_strnstr(str, str2, len);

	printf("Strnstr:	%s", res);
}*/
