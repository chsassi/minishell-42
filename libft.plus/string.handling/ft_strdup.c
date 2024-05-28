/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:16:17 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/28 18:01:33 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*res;
	unsigned int	i;
	int				len;

	i = 0;
	len = ft_strlen(s1);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*int main(void)
{
	char	*s1 = "Ciao";
	char	*sdup;

	sdup = ft_strdup(s1);
	if (!sdup)
		printf("Errore malloc\n");
	printf("La stringa duplicata è: %s\n", sdup);
	free(sdup);
}*/
