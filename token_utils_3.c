/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:40:14 by brulutaj          #+#    #+#             */
/*   Updated: 2024/07/18 17:39:29 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	process_words(t_all *all, char *input, int *index, enum e_state state)
{
	int		start;
	int		len;
	t_elem	*new_elem;

	start = *index;
	len = 0;
	while (input[*index] != '\0')
	{
		if (is_whitespace(input[*index]) || is_special_char(input[*index]))
			break ;
		len++;
		(*index)++;
	}
	new_elem = create_elem(input + start, len, WORD);
	if (new_elem)
	{
		new_elem->state = state;
		add_token(all, new_elem);
	}
	(*index)--;
}

void	proc_op_quot(t_all *all, char *input, int *index, enum e_state state)
{
	int		len;
	t_elem	*new_elem;

	len = 1;
	while (input[*index + len] && is_special_char(input[*input + len]))
		len++;
	new_elem = create_elem(&input[*index], len, WORD);
	if (new_elem)
	{
		new_elem->state = state;
		add_token(all, new_elem);
	}
	*index += len - 1;
}

void	process_op(t_all *all, char *input, int *index, enum e_state state)
{
	enum e_token	token;
	int 			len;
	t_elem			*new_elem;
	
	token = find_token_type(input, index);
	if (state == IN_QUOTE || state == IN_DQUOTE)
	{
		proc_op_quot(all, input, index, state);
		return ;
	}
	len = 1;
	if (token == HERE_DOC || token == DREDIR_OUT)
		len = 2;
	new_elem = create_elem(&input[*index], len, token);
	if (new_elem)
	{
		new_elem->state = state;
		add_token(all, new_elem);
	}
	*index += len - 1;
}
