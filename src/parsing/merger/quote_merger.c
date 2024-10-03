/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_merger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:42:21 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/03 17:08:04 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	*array_of_index(char *input)
{
	int	*arr;
	int	i;
	const int len = count_number_of_tokens(input);
	
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = i;
		i++
	}
	return (arr);
}

char	*trimmed_quote_token(char *str)
{
	char	*s;

	s = NULL;
	if (*str == "\"")
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

t_pars *init_parser(char *input, char **mtx, int *array)
{
	int		i;
	int		quote_number;
	t_pars	*parser;

	i = 0;
	parser = NULL;
	quote_number = quote_tokens(array, input);
	while (input[i] != '\0')
	{
		if (is_quote(input[i]))
		{
			while (ft_strncmp((input + i), mtx[i], ft_strlen(mtx[i])))
				i++;
			if ()
		}
	}
}

// int	count_merges(char *input, char **mtx, int *array)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (input[i] != '\0')
// 	{
// 		if (is_quote(input[i]) && !is_space(input[i - 1]))
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

