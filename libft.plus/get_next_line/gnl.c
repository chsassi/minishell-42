/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:46:08 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "gnl.h"

static int	ft_find_nl(char **res, char **waste, char *line, int bytes)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	if (bytes == 0 && (!*res || !(**res)))
	{
		free(*res);
		*res = NULL;
		return (1);
	}
	i = strchr_gnl(line, '\n');
	if (i == -1)
		tmp = strjoin_gnl(&tmp, line);
	else
	{
		tmp = substr_gnl(line, 0, i);
		*waste = strjoin_gnl(waste, line + i + 1);
	}
	*res = strjoin_gnl(res, tmp);
	free(tmp);
	return (i > -1);
}

static void	read_until_nl(int fd, char **res, char **waste, int bytes)
{
	char	*line;

	line = calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return ;
	while (bytes > 0)
	{
		bytes = read(fd, line, BUFFER_SIZE);
		if (bytes < 0)
			break ;
		line[bytes] = '\0';
		if (ft_find_nl(res, waste, line, bytes))
			break ;
	}
	free(line);
	if (waste[fd] && waste[fd][0] == '\0')
	{
		free(waste[fd]);
		waste[fd] = NULL;
		return ;
	}
}

char	*gnl(int fd)
{
	static char	*waste[4096] = {NULL};
	char		*tmp;
	char		*res;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4096)
		return (NULL);
	res = NULL;
	bytes = 1;
	if (waste[fd] != NULL)
	{
		tmp = strjoin_gnl(&waste[fd], NULL);
		bytes = !ft_find_nl(&res, &waste[fd], tmp, 1);
		if (!bytes)
		{
			free(waste[fd]);
			return (NULL);
		}
		free(tmp);
	}
	read_until_nl(fd, &res, &waste[fd], bytes);
	return (res);
}

/* int main(int ac, char **av)
{
	int fd = open("text.txt", O_RDONLY);
	int fd2 = open("text.txt", O_RDONLY);
	char *s;
	char *s2;

	(void)av;
	if (ac % 2 == 0){
		for (int i = 0; i < 5; i ++){
			s = get_next_line(fd);
			s2 = get_next_line(fd);
			printf("FILE[1] LINE[%d][%s]", i + 1, s);
			printf("FILE[2] LINE[%d][%s]", i + 1, s2);
			free(s);
			free(s2);
		}
		return (0);
	}
	int line = 1;
	for (char *s= get_next_line(fd), *s2 = get_next_line(fd2); 
			s; s = get_next_line(fd), s2 = get_next_line(fd2)){
		printf("FILE[1] LINE[%d][%s]", line, s);
		printf("FILE[2] LINE[%d][%s]", line++, s2);
		free(s);
		free(s2);
	}
}  */
