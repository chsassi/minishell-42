/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:17:24 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*cpd;
	const char	*cps;

	cpd = (char *)dest;
	cps = (const char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	if (cpd > cps)
	{
		while (n--)
			cpd[n] = cps[n];
	}
	else
	{
		while (n--)
			*cpd++ = *cps++;
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
