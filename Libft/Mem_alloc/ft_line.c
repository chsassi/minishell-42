/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:43:00 by brulutaj          #+#    #+#             */
/*   Updated: 2024/03/28 18:43:37 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_line(int fd)
{
	char	*line;

	line = gnl(fd);
	if (!line)
		return (free(line), NULL);
	return (line);
}
