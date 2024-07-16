/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:34:52 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/13 17:50:26 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
/*
int main(void)
{
	char *s = "djfhghgb";
	int fd = open("putendlo.txt", O_WRONLY);
	if (fd == -1)
	{
		printf("Fail open\n");
		return (1);
	}
	ft_putendl_fd(s, fd);
	if (close(fd) == -1)
		printf("Fail close");
	return (0);
}*/