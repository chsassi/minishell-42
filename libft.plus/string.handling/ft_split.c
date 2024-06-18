/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:45:01 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	word_num;

	i = 0;
	word_num = 0;
	while (s && s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			word_num++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (word_num);
}

static size_t	word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_matrix(char **mtx)
{
	size_t	i;

	i = 0;
	if (!mtx)
		return ;
	while (mtx[i])
	{
		free(mtx[i]);
		mtx[i] = NULL;
		i++;
	}
	free(mtx);
	mtx = NULL;
}

char	**new_string(char **mtx, const char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (*s && *s != c)
				len = word_len(s, c);
			mtx[i] = ft_substr(s, 0, len);
			if (!mtx[i])
			{
				free_matrix(mtx);
				return (NULL);
			}
			i++;
			s += len;
		}
	}
	mtx[i] = NULL;
	return (mtx);
}

char	**ft_split(const char *s, char c)
{
	char	**res;

	res = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!res || !s)
		return (NULL);
	res = new_string (res, s, c);
	return (res);
}

/* int		main(int ac, char **av)
{
	int		i = 0;

	if (ac < 2)
	{
		write(1, "No input", 8);
		return (-1);
	}
	char	**res = ft_split(av[1], ' ');
	printf("main pointer: %p\n", res);
	while (res && res[i])
	{
		printf("[%d]\t%s\n", i, res[i]);
		i++;
	}
	free_matrix(res);
} */
