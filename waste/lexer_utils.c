/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:02:16 by brulutaj          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/29 16:20:27 by brulutaj         ###   ########.fr       */
=======
/*   Updated: 2024/07/30 08:57:25 by chsassi          ###   ########.fr       */
>>>>>>> 553c84292251318e92726280dedaa4cc1afea74c
/*                                                                            */
/* ************************************************************************** */

// #include "parser.h"

// int	is_whitespace(char c)
// {
// 	if (c == ' ')
// 		return (1);
// 	return (0);
// }

// int	is_quote(char c)
// {
// 	if (c == '\'' || c == '\"')
// 		return (1);
// 	return (0);
// }

// int	is_special_char(char c)
// {
// 	if (c == '|' || c == '<' || c == '>')
// 		return (1);
// 	return (0);
// }

// void add_word_token(t_parsing *all, char *content, int len, enum e_state state)
// {
// 	t_elem *new_elem;

// 	new_elem = create_elem(content, len, WORD);
// 	if (new_elem)
// 	{
// 		new_elem->state = state;
// 		add_token(all, new_elem);
// 	}
// }