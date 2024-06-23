/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arr_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:50 by mgalmari          #+#    #+#             */
/*   Updated: 2024/06/18 14:34:59 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_word_token(int token)
{
	if (!token || token == PIPE)
		return (CMD);
	else if (token == R_INPUT || token == R_OUTPUT
	|| token == D_RED_OUTPUT)
		return (FILE_W);
	else if (token == D_RED_INPUT)
		return (EOF_DEL);
	else
		return (ARG);
	return (-1);
}

int	find_token(char *str)
{
	if (*str == '\"')
		return (D_QUOTE);
	else if (*str == '\'')
		return (S_QUOTE);
	else if (*str == '|')
		return (PIPE);
	else if (*str == '<' && ft_strlen(str) == 1)
		return (R_INPUT);
	else if (*str == '>' && ft_strlen(str) == 1)
		return (R_OUTPUT);
	else if (*str == '<' && (*str++) == '<')
		return (D_RED_INPUT);
	else if (*str == '>' && (*str++) == '>')
		return (D_RED_OUTPUT);
	else if (*str == '$')
		return (DOLLAR_SIGN);
	return (WORDS);
}

int	first_token_check(int *arr_token, int size)
{
	int	i;

	i = 0;
	if (!arr_token || !arr_token[i])
		return (0);
	else if (arr_token[i] == PIPE)
		return (0);
	while (i < size && arr_token[i])
	{
		while (i < size && (arr_token[i] && arr_token[i] == WORDS))
			i++;
		if (i < size && (arr_token[i] == PIPE 
		|| arr_token[i] == R_INPUT || 
		arr_token[i] == R_OUTPUT || arr_token[i] == D_RED_INPUT
		|| arr_token[i] == D_RED_OUTPUT))
		{
			if (i++ > size || arr_token[i++] != WORDS)
				return (0);
		}
		i++;
	}
	return (1);
}

int	*analyse_words_token(int *arr_token, int size)
{
	int	i;

	i = 0;
	if (!arr_token)
		return (0);
	while (i < size && arr_token[i])
	{
		if (i == 0 && arr_token[i] == WORDS)
			arr_token[i] = get_word_token(0);
		if ((i != 0 && i < size) && arr_token[i] == WORDS)
			arr_token[i] = get_word_token(arr_token[i - 1]);
		i++;
	}
	return (arr_token);
}

int	*get_arr_token(char **mtx, int size)
{
	int	i;
	int	*arr_token;

	i = 0;
	arr_token = ft_calloc(size, sizeof(int));
	if (!arr_token)
		return (NULL);
	while (mtx && mtx[i])
	{
		arr_token[i] = find_token(mtx[i]);
		i++;
	}
	if (!first_token_check(arr_token, size))
		return (NULL);
	arr_token = analyse_words_token(arr_token, size);
	return (arr_token);
}
