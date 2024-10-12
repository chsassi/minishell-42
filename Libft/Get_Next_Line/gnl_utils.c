/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:41:28 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/12 21:05:41 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str && str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	len;
	size_t	s1len;
	size_t	i;
	size_t	j;
	char	*s;

	s1len = ft_strlen_gnl(s1);
	len = s1len + ft_strlen_gnl(s2);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	i = -1;
	while (++i < s1len && s1)
		s[i] = s1[i];
	j = -1;
	while (s2 && s2[++j])
		s[i + j] = s2[j];
	s[len] = '\0';
	free(s1);
	return (s);
}
