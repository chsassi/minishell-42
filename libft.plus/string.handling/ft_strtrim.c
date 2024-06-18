/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:33:58 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	occurrence(const char s1, const char *set)
{
	while (*set)
	{
		if (*set == s1)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && occurrence(*s1, set))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && occurrence(s1[len - 1], set))
		len--;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len > 0)
	{
		res[len - 1] = s1[len - 1];
		len--;
	}
	return (res);
}

/* int		main(void)
{
	const char	str[] = "xxxxxCiaoxxxxx";
	const char	set[] = "x";

	char		*res = ft_strtrim(str, set);
	printf("Trim:	%s\n", res);
} */
