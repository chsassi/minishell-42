/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:40:14 by brulutaj          #+#    #+#             */
/*   Updated: 2024/07/23 11:21:13 by brulutaj         ###   ########.fr       */
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

void	proc_qoute(t_all *all, char *input, int *index, enum e_state state)
{
	int	start;
	int	len;
	char quote;

	start = *index;
	len = 0;
	quote = input[*index];
	(*index)++;
	while (input[*index] != '\0' && input[*index] != quote)
	{
		if (state == IN_DQUOTE && input[*index] == '$')
		{
			add_
		}
	}
}