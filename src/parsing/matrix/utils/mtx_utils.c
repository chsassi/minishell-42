/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:49:01 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/11 20:12:41 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int	is_special_char(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	is_normal_letter(char *input, int i)
{
	if (input[i] != ' ' && !is_special_char(input[i])
		&& !is_quote(input[i]))
		return (1);
	return (0);
}

void	count_normal_token(char *input, int *i, int *token)
{
	while (is_normal_letter(input, *i) && input[*i] != '\0')
		(*i)++;
	(*i)--;
	(*token)++;
}

int	count_quote_token(char *input, int *i, int *token)
{
	int	check_1;
	int	check_2;

	check_1 = 0;
	check_2 = 0;
	if (input[*i] == '\'')
	{
		check_1 = count_single_quote_token(input, i, token);
		if (check_1 == -1)
			return (-1);
	}
	else
	{
		check_2 = count_double_quote_token(input, i, token);
		if (check_2 == -1)
			return (-1);
	}
	return (1);
}
