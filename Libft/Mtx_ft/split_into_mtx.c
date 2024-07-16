/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_into_mtx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:06:34 by brulutaj          #+#    #+#             */
/*   Updated: 2024/03/28 18:41:05 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**split_into_mtx(char *str)
{
	char	**mtx;

	if (!str)
		return (NULL);
	mtx = ft_split(str, '\n');
	free(str);
	return (mtx);
}
