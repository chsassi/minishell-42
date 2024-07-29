/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:21:29 by brulutaj          #+#    #+#             */
/*   Updated: 2024/07/29 11:22:59 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "parser.h"

// enum e_token	get_quote_token(char c)
// {
// 	if (c == '\'')
// 		return (QUOTE);
// 	return (DOUBLE_QUOTE);
// }

// enum e_token	get_special_token(const char *input, int *index)
// {
// 	if (input[*index] == '$')
// 		return (ENV);
// 	if (input[*index] == '|')
// 		return (PIPE_LINE);
// 	if (input[*index] == '<')
// 		return (input_red_token(input, index));
// 	if (input[*index] == '>')
// 		return (output_red_token(input, index));
// 	return (WORD);
// }

// enum e_token	input_red_token(const char *input, int *index)
// {
// 	if (input[*index + 1] == '<')
// 	{
// 		(*index)++;
// 		return (HERE_DOC);
// 	}
// 	return (REDIR_IN);
// }

// enum e_token	output_red_token(const char *input, int *index)
// {
// 	if (input[*index + 1] == '>')
// 	{
// 		(*index)++;
// 		return (DREDIR_OUT);
// 	}
// 	return (REDIR_OUT);
// }

// enum e_token	find_token_type(const char *input, int *index)
// {
// 	if (input[*index] == '\0' || input[*index] == '\n')
// 		return (NEW_LINE);
// 	if (is_whitespace(input[*index]))
// 		return (WHITE_SPACE);
// 	if (is_quote(input[*index]))
// 		return (get_quote_token(input[*index]));
// 	if (is_special_char(input[*index]))
// 		return (get_special_token(input, index));
// 	return (WORD);
// }
