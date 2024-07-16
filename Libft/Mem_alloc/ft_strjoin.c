/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:30:23 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/13 11:37:11 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[s1_len + i] = s2[i];
		i++;
	}
	str[s1_len + i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char s1[] = "porco";
	char s2[] = " dio";
	char *strjoin = ft_strjoin(s1, s2);
	printf("nuova stringa creata: %s", strjoin);
	free (strjoin);
	return (0);
}*/
