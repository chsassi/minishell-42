/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:49:01 by brulutaj          #+#    #+#             */
/*   Updated: 2024/07/31 18:17:13 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parser.h"

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
		&& !is_quote(input[i]) && input[i] != '$')
		return (1);
	return (0);
}

void	len_normal_token(char *input, int *i, int *token)
{
	 while (is_normal_letter(input, *i) && input[*i] != '\0')
		(*i)++;
	(*token)++;
}

int	len_quote_token(char *input, int *i, int *token)
{
	if (input[*i] == '\'')
	{
		while (input[*i] != '\0' && input[*i] != '\'')
			(*i)++;
		if (input[*i] == '\0')
			return (-1);
		(*token)++;
			return (1);
	}
	else (input[*i] == '\"')
	{
		while (input[*i] != '\0' && input[*i] != '\"')
			(*i)++;
		if (input[*i] == '\0')
			return (-1);
		(*token)++;
			return (1);
	}
	return (0);
}
