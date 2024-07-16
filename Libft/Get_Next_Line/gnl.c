/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:35:21 by brulutaj          #+#    #+#             */
/*   Updated: 2024/03/25 08:48:21 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_linea(char	*str)
{
	int		i;
	char	*linea;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	linea = (char *)malloc(sizeof(char) * (i + 2));
	if (!linea)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		linea[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		linea[i] = str[i];
		i++;
	}
	linea[i] = '\0';
	return (linea);
}

char	*ft_resto(char *str)
{
	int		i;
	int		j;
	char	*resto;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (ft_strlen_gnl(str) - i == 0)
	{
		free(str);
		return (NULL);
	}
	resto = (char *)malloc(sizeof(char) * (ft_strlen_gnl(str) - i + 1));
	if (!resto)
		return (NULL);
	j = 0;
	while (str[i])
		resto[j++] = str[i++];
	resto[j] = '\0';
	free(str);
	return (resto);
}

char	*read_line(int fd, char *str)
{
	char	*buff;
	int		bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr_gnl(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
			break ;
		buff[bytes] = '\0';
		str = ft_strjoin_gnl(str, buff);
	}
	if (ft_strlen_gnl(str) == 0)
	{
		free(str);
		str = NULL;
	}
	free(buff);
	return (str);
}

char	*gnl(int fd)
{
	static char	*str[4096] = {NULL};
	char		*linea;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	str[fd] = read_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	linea = ft_linea(str[fd]);
	str[fd] = ft_resto(str[fd]);
	return (linea);
}

// int main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *line = gnl(fd);
// 	int i = 0;
// 	printf("[%d]{%s}",i++, line);
// 	while (line && i < 3)
// 	{
// 		free(line);
// 		line = gnl(fd);
// 		printf("[%d]{%s}",i++, line);
// 	}
// 	free(line);
// 	close (fd);
// }