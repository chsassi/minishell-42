/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:25:57 by brulutaj          #+#    #+#             */
/*   Updated: 2024/08/09 14:12:46 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	env_token_length(char *input, int *i, int *token)
{
	if (input[(*i) + 1] == '\0')
		return ((void)(*token)++);
	(*i)++;
	if (input[*i] == '?')
	{
		(*token)++;
		return ;
	}
	else if (input[*i] == '_' || ft_isalpha(input[*i]))
	{
		if (input[(*i) + 1] == '\0')
		{
			(*token)++;
			return ;
		}
		(*i)++;
		while (input[*i] == '_' || ft_isalnum(input[*i]))
			(*i)++;
		(*i)--;
		(*token)++;
	}
	else
		(*token)++;
}

int	single_quote_token_length(char *input, int *i, int *token)
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
	return(1);
}

int	double_quote_token_length(char *input, int *i, int *token)
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
	return(1);
}

void	operator_token_length(char *input, int *i, int *token)
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
			return;
		}
		(*token)++;
	}
	else
		(*token)++;
}
