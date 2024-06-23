/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mtx_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:50 by mgalmari          #+#    #+#             */
/*   Updated: 2024/06/18 14:35:00 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_words(char *s)
{
	int	i;
	int	tmp;
	int	word_num;

	i = 0;
	word_num = 0;
	tmp = 0;
	if (!s || !s[i])
		return (0);
	while (s && s[i])
	{
		while (s[i] && check_spaces(s[i]) == 1)
			i++;
		if (s[i])
			word_num++;
		if (s[i] && (check_spaces(s[i]) != 1))
			tmp = handle_not_spaces(&s[i]);
		if (tmp == -1)
			return (-1);
		i += tmp;
	}
	return (word_num);
}

int	word_len(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[i])
		return (0);
	if (check_spaces(s[i]) == PIPE || check_spaces(s[i]) == R_INPUT
	|| check_spaces(s[i]) == R_OUTPUT
	|| check_spaces(s[i]) == DOLLAR_SIGN)
		return (handle_operators(&s[i]));
	if (s[i] && (check_spaces(s[i]) == D_QUOTE || check_spaces(s[i]) == S_QUOTE))
		return (handle_quotes(s));
	while (s[i] && !check_spaces(s[i]))
		i++;
	return (i);
}

char	**new_string(char **mtx, char *s)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		while (*s && check_spaces(*s) == 1)
			s++;
		if (*s)
		{
			if (*s && check_spaces(*s) != 1)
				len = word_len(s);
			mtx[i] = ft_substr(s, 0, len);
			if (!mtx[i])
			{
				free_mtx(mtx);
				return (NULL);
			}
			i++;
			s += len;
		}
	}
	mtx[i] = NULL;
	return (mtx);
}

char	**get_mtx_from_input(t_parsing parsing)
{
	char	**res;
	int		words;

	words = count_words(parsing.input);
	if (words == -1)
		return (NULL);
	res = ft_calloc((words + 1), sizeof(char *));
	if (!res || !parsing.input)
		return (NULL);
	res = new_string (res, parsing.input);
	return (res);
}
