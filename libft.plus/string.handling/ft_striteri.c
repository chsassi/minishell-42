/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:02:51 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/* void	ulstr(unsigned int i, char *str)
{
	if (*str >= 65 && *str <= 90)
		*str += 32;
	else if (*str >= 97 && *str <= 122)
		*str -= 32;

}

int		main(void)
{
	char	str[] = "Ciao, come va?";
	int		i = 0;
	int		len = ft_strlen(str);

	ft_striteri(str, ulstr);
	while (str[i] && i < len)
	{
		printf("Striteri: %c\n", str[i]);
		i++;
	}
} */
