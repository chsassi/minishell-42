/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:33:54 by brulutaj          #+#    #+#             */
/*   Updated: 2024/08/02 17:56:18 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	find_number_of_tokens(char *input)
{
	int i;
	int	check;
	int token;

	i = 0;
	token = 0;
	check = 0;
	while (input && input[i])
	{
		if (input[i] == '$')
			env_token_length(input, &i, &token);
		else if (is_special_char(input[i]))
			token++;
		else if (is_quote(input[i]))
		{
			check = quote_token_length(input, &i, &token);
			if (check == -1)
				return (-1);
		}
		else if (is_normal_letter(input, i))
			normal_token_length(input, &i, &token);
		if (input[i] != '\0')
			i++;
	}
	return (token);
}

// int	token_len(char *input, enum e_state *state)
// {
// 	int	i;

// 	i = 0;
	
// }
