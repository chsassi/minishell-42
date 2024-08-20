/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:33:54 by brulutaj          #+#    #+#             */
/*   Updated: 2024/08/20 09:53:14 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	count_number_of_tokens(char *input)
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
			count_env_token(input, &i, &token);
		else if (is_special_char(input[i]))
			count_operator_token(input, &i, &token);
		else if (is_quote(input[i]))
		{
			check = count_quote_token(input, &i, &token);
			if (check == -1)
				return (-1);
		}
		else if (is_normal_letter(input, i))
			count_normal_token(input, &i, &token);
		if (input[i] != '\0')
			i++;
	}
	return (token);
}

int	token_length(char *input)
{
	if (*input)
	{
		if (*input == '$')
			return (env_token_length(input));
		else if (is_special_char(*input))
			return (operator_token_length(input));
		else if (is_quote(*input))
			return(quote_token_length(input));
		else
			return (normal_token_length(input));
	}
	return(0);
}

char	**fill_mtx(char **mtx, char *input)
{
	int	i;
	int	len;

	while (*input)
	{
		while (*input && *input == ' ')
			input++;
		if (*input)
		{
			len = token_length(input);
			mtx[i] = ft_substr(input, 0, len);
			if (mtx[i] == NULL)
			{
				free_mtx(mtx);
				return (NULL);
			}
			i++;
			input += len;
		}
	}
	mtx[i] == NULL;
	return (mtx);
}

char	**create_mtx(char *input)
{
	char	**mtx;
	int		i;
	int		number_of_tokens;

	i = 0;
	number_of_tokens = count_number_of_tokens(input);
	if (number_of_tokens == -1)
		return (ft_putstr_fd("Closing quotes missing", 2), NULL);
	mtx = (char **)ft_calloc(number_of_tokens, sizeof(char *));
	if (!mtx || !input)
	{
		free(mtx);
		return (NULL);
	}
	
	
}

// int	token_len(char *input, enum e_state *state)
// {
// 	int	i;

// 	i = 0;
	
// }
