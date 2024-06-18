/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:31:43 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_strcat(char *s, char *s2, char *fin)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s && s[i])
	{
		fin[i] = s[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		fin[i + j] = s2[j];
		j++;
	}
	fin[i + j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t1;
	char	*t2;
	char	*fin;

	t1 = (char *)s1;
	t2 = (char *)s2;
/* 	if (s1 == NULL || s2 == NULL)
		return (NULL); */
	fin = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!fin)
		return (NULL);
	ft_strcat(t1, t2, fin);
	return (fin);
}

/*int		main(void)
{
	char	s1[] = "Ciao";
	char	s2[] = ", come va?";
	char	*res;

	res = ft_strjoin(s1, s2);
	printf("Join:	%s\n", res);
	free(res);
}*/
