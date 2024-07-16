/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:02:16 by brulutaj          #+#    #+#             */
/*   Updated: 2024/07/16 17:06:36 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_whitespace(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	is_qoute(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int	is_special_char(char c)
{
	if (c == '$' || c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	is_operator(enum e_token token)
{
	if (token == PIPE_LINE || token == REDIR_IN
		|| token == REDIR_OUT || token == HERE_DOC
		|| token == DREDIR_OUT)
		return (1);
	return (0);
}
