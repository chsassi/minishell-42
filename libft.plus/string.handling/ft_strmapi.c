/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:02:34 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*ptr;

	i = 0;
	len = ft_strlen(s);
	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/* char	rotone_fc(unsigned int i, char c)
{
	if ((i % 2 == 0) && ((c >= 65 && c <= 89) || (c >= 97 && c <= 121)))
		c += 1;
	else if ((c == 90)|| (c == 122))
		c -= 25;
	return (c);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		printf("Input Error.");
	char			*str = ft_strmapi(av[1], rotone_fc);
	printf("Mapi [Rotone Fuori Controllo]: %s\n", str);
	free(str);
} */
