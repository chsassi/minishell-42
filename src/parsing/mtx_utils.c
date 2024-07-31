/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:49:01 by brulutaj          #+#    #+#             */
/*   Updated: 2024/07/31 15:46:37 by brulutaj         ###   ########.fr       */
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
		&& !is_quote(input[i]))
		return (1);
	return (0);
}

int	len_normal_token(char *input, int *i, int *token)
{
	 while (is_normal_letter(input, *i))
}

int	len_quote_token(char *input, int *i, int *token)
{
	if (input[*i] == '\'')
	{
		while (input[*i] != '\0' && input[*i] != '\'')
			*i++;
	}
}