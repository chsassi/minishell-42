/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_merger_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:42:21 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/05 19:00:20 by brulutaj         ###   ########.fr       */
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
	if (!len)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	while (input[i] != '\0')
	{
		while (input[i] == 32)
			i++;
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
	if (*str == '\"')
	{
		s = ft_strtrim(str, "\"");
		free(str);
	}
	else
	{
		s = ft_strtrim(str, "\'");
		free(str);
	}
	return (s);
}

char	*merge_string(int *arr, char **mtx, int *i)
{
	char	*str;

	str = NULL;
	if (arr[*i] == NO)
		str = ft_strdup(mtx[*i]);
	else
	{
		while (arr[*i] == NEXT)
		{
			if (str == NULL)
				str = ft_strjoin(trimm_quotes(mtx[*i]),
						trimm_quotes(mtx[(*i) + 1]));
			else
				str = ft_strjoin_gnl(str, trimm_quotes(mtx[(*i) + 1]));
			(*i)++;
		}
	}
	if (mtx[*i] == NULL)
		(*i)++;
	return (str);
}
