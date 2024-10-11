/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:25:57 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/11 20:13:32 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	count_single_quote_token(char *input, int *i, int *token)
{
	if (input[(*i) + 1] == '\'')
	{
		(*i)++;
		(*token)++;
		return (0);
	}
	(*i)++;
	while (input[*i] != '\0' && input[*i] != '\'')
		(*i)++;
	if (input[*i] == '\0')
		return (-1);
	(*token)++;
	return (1);
}

int	count_double_quote_token(char *input, int *i, int *token)
{
	if (input[(*i) + 1] == '\"')
	{
		(*i)++;
		(*token)++;
		return (0);
	}
	(*i)++;
	while (input[*i] != '\0' && input[*i] != '\"')
		(*i)++;
	if (input[*i] == '\0')
		return (-1);
	(*token)++;
	return (1);
}

void	count_operator_token(char *input, int *i, int *token)
{
	if (input[*i] == '>')
	{
		if (input[(*i) + 1] == '>')
		{
			(*i)++;
			(*token)++;
			return ;
		}
		(*token)++;
	}
	else if (input[*i] == '<')
	{
		if (input[(*i) + 1] == '<')
		{
			(*i)++;
			(*token)++;
			return ;
		}
		(*token)++;
	}
	else
		(*token)++;
}
