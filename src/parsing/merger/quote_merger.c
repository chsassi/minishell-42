/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_merger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:42:21 by brulutaj          #+#    #+#             */
/*   Updated: 2024/09/30 16:21:49 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	count_merges(char *input, char **mtx, int *array)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i] != '\0')
	{
		if (is_quote(input[i]) && !is_space(input[i - 1]))
			count++;
		i++;
	}
	return (count);
}

