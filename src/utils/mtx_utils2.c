/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:25:57 by brulutaj          #+#    #+#             */
/*   Updated: 2024/08/01 11:58:44 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	len_env_token(char *input, int *i, int *token)
{
	(*i)++;
	if (input[*i] == '_' || ft_isalpha(input[*i]) || input[*i] == '?')
	{
		(*i)++;
		while (input[*i] == '_' || ft_isalnum(input[*i]))
			(*i)++;
	}
	(*token)++;
}
