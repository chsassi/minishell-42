/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <chsassi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:36:52 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*cpd;
	char	*cps;

	i = 0;
	cpd = (char *)dest;
	cps = (char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		cpd[i] = cps[i];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	char	*src = "Ciao";
	char	dest[10] = "isso vado";
	size_t	n;

	ft_memcpy(dest, src, 4);
	printf("Copia:  %s", dest);
} */
