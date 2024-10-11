/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:11:14 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/11 20:17:31 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	assign_token(char *str)
{
	if (*str == '\'')
		return (QUOTE);
	else if (*str == '\"')
		return (DOUBLE_QUOTE);
	else if (*str == '|')
		return (PIPE_LINE);
	else if (*str == '<' && *(str + 1) == '<')
		return (HERE_DOC);
	else if (*str == '<')
		return (REDIR_IN);
	else if (*str == '>' && *(str + 1) == '>')
		return (DREDIR_OUT);
	else if (*str == '>')
		return (REDIR_OUT);
	return (WORD);
}

int	*token_arr(char **mtx)
{
	int	*arr;
	int	len;
	int	i;

	len = ft_rowlen(mtx);
	if (len == 0)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	i = 0;
	while (mtx[i])
	{
		arr[i] = assign_token(mtx[i]);
		i++;
	}
	return (arr);
}
