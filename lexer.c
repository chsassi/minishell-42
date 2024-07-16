/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:26:06 by brulutaj          #+#    #+#             */
/*   Updated: 2024/07/16 10:32:06 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// const char *token_to_string(enum e_token token)
// {
//     switch (token)
//     {
//         case WORD: return "WORD";
//         case WHITE_SPACE: return "WHITE_SPACE";
//         case NEW_LINE: return "NEW_LINE";
//         case QUOTE: return "QUOTE";
//         case DOUBLE_QUOTE: return "DOUBLE_QUOTE";
//         case ENV: return "ENV";
//         case PIPE_LINE: return "PIPE_LINE";
//         case REDIR_IN: return "REDIR_IN";
//         case REDIR_OUT: return "REDIR_OUT";
//         case HERE_DOC: return "HERE_DOC";
//         case DREDIR_OUT: return "DREDIR_OUT";
//         default: return "UNKNOWN";
//     }
// }

enum e_state update_state(enum e_state state, enum e_token token)
{
	enum e_state new_state;

	new_state = state;
	if (state == GENERAL)
	{
		if (token == DOUBLE_QUOTE)
			new_state = IN_DQUOTE;
		else if (token == QUOTE)
			new_state = IN_QUOTE;
	}
	else if (state == IN_DQUOTE)
	{
		if (token == DOUBLE_QUOTE)
			 new_state = GENERAL;
	}
	else if (state == IN_QUOTE)
	{
		if (token == QUOTE)
			new_state = GENERAL;
	}
	return (new_state);
}

t_all	*assign_tokens(char *input)
{
	t_all			*all;
	int				i;
	enum e_token	token;
	enum e_state	state;

	all = init_all();
	if (!all)
		return (NULL);
	i = 0;
	state = GENERAL;
	while (input[i] != '\0')
	{
		token = token_type(input, &i);
		//printf("Character: '%c', Token: %s\n", input[i], token_to_string(token));
        i++;
	}
    return (all);
}