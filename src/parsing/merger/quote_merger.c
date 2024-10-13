/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_merger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:42:21 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/12 18:40:40 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	type_of_merge(char *str, int start, int end)
{
	if (is_quote(str[start]) || is_normal_letter(str, start))
	{
		if (start != 0 && str[end] != '\0')
		{
			if ((is_quote(str[start - 1]) || is_normal_letter(str, start - 1))
				&& (is_quote(str[end]) || is_normal_letter(str, end)))
				return (BOTH);
		}
		if (start != 0)
		{
			if (is_quote(str[start - 1]) || is_normal_letter(str, start - 1))
				return (PREV);
		}
		if (str[end] != '\0')
		{
			if (is_quote(str[end]) || is_normal_letter(str, end))
				return (NEXT);
		}
	}
	return (NO);
}

int	*array_of_merges(char *input, char **mtx)
{
	int			*arr;
	int			i;
	int			j;
	const int	len = count_number_of_tokens(input);

	i = 0;
	j = 0;
	arr = ft_calloc(sizeof(int), len);
	if (!arr)
		return (NULL);
	arr[0] = NO;
	if (len == 1)
		return (arr);
	while (input[i] != '\0')
	{
		while (input[i] == 32)
			i++;
		if (input[i] == '\0')
			break ;
		arr[j] = type_of_merge(input, i, (i + ft_strlen(mtx[j])));
		i += ft_strlen(mtx[j]);
		j++;
	}
	return (arr);
}

int	*process_arr_merger(char *input, char **mtx)
{
	int	*arr;
	int	i;

	arr = array_of_merges(input, mtx);
	if (!arr)
		return (NULL);
	i = 0;
	while (mtx[i] != NULL)
	{
		if (arr[i] == BOTH)
			arr[i] = NEXT;
		else if (arr[i] == PREV)
			arr[i] = NO;
		i++;
	}
	return (arr);
}

char	*trimm_quotes(char *str)
{
	char	*s;

	s = NULL;
	if (str && *str == '\"')
		s = ft_strtrim(str, "\"");
	else
		s = ft_strtrim(str, "\'");
	return (s);
}

char	*merge_string(int *arr, char **mtx, int *i)
{
	t_merge	p;

	p = (t_merge){0};
	if (arr[*i] == NO)
	{
		p.tmp = trimm_quotes(mtx[*i]);
		p.str = ft_strdup(p.tmp);
		free(p.tmp);
	}
	else
	{
		while (arr[*i] == NEXT)
		{
			if (p.str == NULL)
				p.str = joined_merger(mtx[(*i)], mtx[(*i) + 1], 1);
			else
				p.str = joined_merger(p.str, mtx[(*i) + 1], 0);
			(*i)++;
		}
	}
	if (mtx[*i] != NULL)
		(*i)++;
	return (p.str);
}
