/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_merger__utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:13:02 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/02 11:32:10 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	quote_tokens(int *array, int *input)
{
	int	len;
	int count;
	int	i;
	
	i = 0;
	count = 0;
	len = count_number_of_tokens(input);
	while (i < len)
	{
		if (array[i] == DOUBLE_QUOTE || array[i] == QUOTE)
			count++;
		i++;
	}
	return(count);
}