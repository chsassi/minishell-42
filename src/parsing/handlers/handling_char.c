/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:50 by mgalmari          #+#    #+#             */
/*   Updated: 2024/06/18 14:35:00 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_spaces(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else if (c == '\"')
		return (D_QUOTE);
	else if (c == '\'')
		return (S_QUOTE);
	else if (c == '|')
		return (PIPE);
	else if (c == '<')
		return (R_INPUT);
	else if (c == '>')
		return (R_OUTPUT);
	else if (c == '$')
		return (DOLLAR_SIGN);
	return (0);
}

int	handle_quotes(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[i])
		return (0);
	if (check_spaces(s[i]) == D_QUOTE)
	{
		if (s[++i] && check_spaces(s[i]) == D_QUOTE)
			return (++i);
		while ((s && s[i]) && check_spaces(s[i]) != D_QUOTE)
			i++;
	}
	else if (check_spaces(s[i]) == S_QUOTE)
	{
		if (s[++i] && check_spaces(s[i]) == S_QUOTE)
			return (++i);
		while ((s && s[i]) && check_spaces(s[i]) != S_QUOTE)
			i++;
	}
	if (!s[i])
		return (-1);
	return (++i);
}

int	handle_operators(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[i])
		return (0);
	if (s[i] && check_spaces(s[i]) == PIPE)
		return(++i);
	else if (s[i] && check_spaces(s[i]) == R_INPUT)
	{
		if (s[i + 1] && check_spaces(s[i + 1]) == R_INPUT)
			return (2);
		return (++i);
	}
	else if (s[i] && check_spaces(s[i]) == R_OUTPUT)
	{
		if (s[i + 1] && check_spaces(s[i + 1]) == R_OUTPUT)
			return (2);
		return (++i);
	}
	else if (s[i] && check_spaces(s[i++]) == DOLLAR_SIGN)
	{
		while (s[i] && !check_spaces(s[i]))
			i++;
	}
	return (i);
}

int	handle_not_spaces(char *s)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	if (!s || !s[i])
		return (0);
	if (s[i] && (check_spaces(s[i]) == D_QUOTE || check_spaces(s[i]) == S_QUOTE))
		tmp = handle_quotes(&s[i]);
	if (s[i] && (check_spaces(s[i]) == PIPE || check_spaces(s[i]) == R_INPUT
	|| check_spaces(s[i]) == R_OUTPUT || check_spaces(s[i]) == DOLLAR_SIGN))
		tmp = handle_operators(&s[i]);
	while (s[i] && !check_spaces(s[i]))
		i++;
	if (tmp == -1)
		return (-1);
	i += tmp;
	return (i);
}

int	get_len_word(char *str, int	index)
{
	int	len;

	len = 0;
	if (index < 0)
		return (-1);
	if (!str || !str[index])
		return (0);
	while ((str && str[index]) && !check_spaces(str[index++]))
		len++;
	return (len);
}

int	get_index_special_char(char *str, char c)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (-1);
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
