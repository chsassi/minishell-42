/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:02:16 by brulutaj          #+#    #+#             */
/*   Updated: 2024/07/23 15:01:29 by brulutaj         ###   ########.fr       */
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
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

void add_word_token(t_parsing *all, char *content, int len, enum e_state state)
{
	t_elem *new_elem;

	new_elem = create_elem(content, len, WORD);
	if (new_elem)
	{
		new_elem->state = state;
		add_token(all, new_elem);
	}
}
