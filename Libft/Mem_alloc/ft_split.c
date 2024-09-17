/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:06:58 by brulutaj          #+#    #+#             */
/*   Updated: 2024/03/28 10:47:40 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (words);
}

static size_t	w_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_matrix(char **mtx)
{
	size_t	j;

	j = 0;
	while (mtx[j])
	{
		free(mtx[j]);
		mtx[j] = NULL;
		j++;
	}
	free(mtx);
	mtx = NULL;
}

static char	**new_arr(char **mtx, const char *s, char c)
{
	size_t	j;
	size_t	len;

	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (*s && *s != c)
				len = w_len(s, c);
			mtx[j] = ft_substr(s, 0, len);
			if (mtx[j] == NULL)
			{
				free_matrix(mtx);
				return (NULL);
			}
			j++;
			s += len;
		}
	}
	mtx[j] = NULL;
	return (mtx);
}

char	**ft_split(const char *s, char c)
{
	char	**matrix;

	matrix = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!matrix || !s)
	{
		free(matrix);
		return (NULL);
	}
	matrix = new_arr(matrix, s, c);
	return (matrix);
}
/*
int	main(void)
{
	char s[] = "  RODE ALO EVER ORTA ESENGU";
	char **split;
	int i = 0;
	int j = 0;
	//printf("%zu", count_words(s, ' '));
	split = ft_split(s, ' ');
	//printf ("Stringa splittata: \n");
	while (i < 5)
	{
		write(1, split[i], ft_strlen(split[i]));
		write(1, "\n", 1);
		i++;
	}
	while (j < 5)
	{
		free(split[j]);
		j++;
	}
	free(split);
	return (0);
}*/