/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:23:04 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/08 18:37:29 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_pipe_error(t_pars *parser)
{
	if (parser->prev == NULL || parser->next->str == NULL)
		return (0);
	else if (parser->next->type == PIPE_LINE)
		return (0);
	else if (parser->prev->type == REDIR_IN || parser->next->type == REDIR_IN)
		return (0);
	else if (parser->prev->type == REDIR_OUT || parser->next->type == REDIR_OUT)
		return (0);
	else if (parser->prev->type == HERE_DOC || parser->next->type == HERE_DOC)
		return (0);
	else if (parser->prev->type == DREDIR_OUT
		|| parser->next->type == DREDIR_OUT)
		return (0);
	return (1);
}

int check_redir_error(t_pars *parser)
{
	if (parser->next == NULL)
		return (0);
	else if (parser->next->type == REDIR_IN || parser->next->type == REDIR_OUT
			|| parser->next->type == HERE_DOC || parser->next->type == DREDIR_OUT)
		return (0);
	else if (parser->prev->type == PIPE_LINE)
		return (0);
	return (1);
}

int	check_all_errors(t_pars *parser)
{
	int check;

	check = 1;
	while (parser)
	{
		if (parser->type == PIPE_LINE)
			check = check_pipe_error(parser);
		else if (parser->type == REDIR_IN || parser->type == REDIR_OUT
			|| parser->type == HERE_DOC || parser->type == DREDIR_OUT)
			check = check_redir_error(parser);
		parser = parser->next;
	}
	return (check);
}