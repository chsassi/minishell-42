/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:52:23 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/06 17:57:14 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(const char s1, const char *set)
{
	while (*set != '\0')
	{
		if (*set == s1)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trim;
	size_t	len;

	while (s1 && *s1 != '\0' && is_set(*s1, set))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && is_set(s1[len - 1], set))
		len--;
	trim = malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (NULL);
	trim[len] = '\0';
	while (len > 0)
	{
		trim[len - 1] = s1[len - 1];
		len--;
	}
	return (trim);
}
/*
int	main(void)
{
	char s1[] = "dev Porco Dio ved";
	char set[] = "dev";
	char *strtrim = ft_strtrim(s1, set);
	printf ("stringa normale: %s\n", s1);
	printf ("stringa trimmata: %s", strtrim);
	free (strtrim);
	return (0);
}*/