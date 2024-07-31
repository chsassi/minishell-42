/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:33:54 by brulutaj          #+#    #+#             */
/*   Updated: 2024/07/31 15:40:09 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parser.h"

int	find_number_of_tokens(char *input)
{
	int i;
	int token;

	i = 0;
	token = 0;
	while (input && input[i])
	{
		if (is_special_char(input[i]))
			token++;
		else if (is_quote(input[i]))
			len_quote_token(input, &i, &token);
		else if (is_normal_letter(input, i))
			len_normal_token(input, &i, &token);
		i++;
	}
	return (token);
}

int	token_len(char *input, enum e_state *state)
{
	int	i;

	i = 0;
	
}
