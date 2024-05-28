/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:31:43 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/28 18:01:33 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	size_t			s1_len;
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	s1_len = ft_strlen(s1);
	len = s1_len + ft_strlen(s2) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1_len)
		res[i++] = s1[j++];
	j = 0;
	while (i < len)
		res[i++] = s2[j++];
	return (res);
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
