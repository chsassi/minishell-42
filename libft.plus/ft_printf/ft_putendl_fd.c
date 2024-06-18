/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:53:11 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, xstrlen(s));
	write(fd, "\n", 1);
}
/* 
int		main (void)
{
	char *str = "Isso";
	int fd = open("test.txt", O_WRONLY);
	if (fd == -1)
	{
		printf("Failure during opening\n");
		return (1);
	}
	ft_putendl_fd(str, fd);
	close(fd);
} */
