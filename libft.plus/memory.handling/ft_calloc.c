/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:17:24 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	if (size > 0)
		ft_bzero(array, (nmemb * size));
	return (array);
}

/* int main(void)
{
	size_t	nmemb = 5;
	size_t	size = sizeof(int);
	int		*array = (int *)ft_calloc(nmemb, size);

	if (array != NULL)
	{
		size_t i = 0;
		while (i < nmemb)
		{
			array[i] = i + 1;
			i++;
		}
		size_t j = 0;
		while (j < nmemb)
		{
			printf("%d\n", array[j]);
			j++;
		}
		free(array);
	}
} */
