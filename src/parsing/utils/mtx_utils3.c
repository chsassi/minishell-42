/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:01:19 by brulutaj          #+#    #+#             */
/*   Updated: 2024/09/12 17:05:20 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	operator_token_length(char *input)
{
	int i;

	i = 0;
	if (input[i] == '>')
	{
		i++;
		if (input[i] == '>')
			i++;
		return(i);
	}
	else if (input[i] == '<')
	{
		i++;
		if (input[i] == '<')
			i++;
		return(i);
	}
	else
		return(1);
}

int quote_token_length(char *input)
{
	int i;

	i = 0;
	if (*input == '\'')
	{
		if (input[i + 1] == '\'')
			return(2);
		i++;
		while (input[i] != '\'')
			i++;
		i++;
		return(i);
	}
	else
	{
		if (input[i + 1] == '\"')
			return(2);
		i++;
		while (input[i] != '\"')
			i++;
		i++;
		return(i);
	}
	return (i);
}

int normal_token_length(char *input)
{
	int	i;

	i = 0;
	while (input[i] != ' ' && !is_special_char(input[i])
			&& !is_quote(input[i]) && input[i] != '$' && input[i])
			i++;
	return (i);
}
