/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <chsassi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:16:53 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char	*ptr;

	ptr = (char *)s;
	while (len > 0)
	{
		*ptr = c;
		ptr++;
		len --;
	}
	return (s);
}

/* int		main(void)
{
	char	str[] = "Ciao";
	size_t len = ft_strlen(str);
	int i = 0;

	char *str1 = ft_memset(str, 57, len);
	while (str[i] != '\0')
	{
		printf("Memset:		%c\n", str[i]);
		i++;
	}
} */
