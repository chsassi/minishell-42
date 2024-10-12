/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:29:46 by brulutaj          #+#    #+#             */
/*   Updated: 2023/10/27 20:07:08 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) *(ft_strlen(s) + 1));
	if (ptr == 0)
		return (NULL);
	while (s && s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int main(void)
{
	char s[] = "redfoil";
	printf("stringa duplicata: %s", ft_strdup(s));
	return (0);
}*/