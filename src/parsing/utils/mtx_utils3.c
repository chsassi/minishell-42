/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:01:19 by brulutaj          #+#    #+#             */
/*   Updated: 2024/08/19 14:29:22 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	env_token_length(char *input)
{
    int	i;

    i = 1;
    if (input[i] != '\0')
    {
		if (input[i] == '?')
			return (i++);
		else if (input[i] == '_' || ft_isalpha(input[i]))
		{
			i++;
			while (input[i] == '_' || ft_isalnum(input[i]))
			    i++;
		}
    }
	return (i);
}

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
		return(i++);
}

int quote_token_length(char *input)
{
	int i;

	i = 1;
	if (*input == '\'')
	{
		if (input[i] == '\'')
			return(i++);
		while (input[i] != '\'')
			i++;
		return(i);
	}
	else
	{
		if (input[i] == '\"')
			return(i++);
		while (input[i] != '\"')
			i++;
		return(i);
	}
	return (i);
}
