/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_merger_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:13:02 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/12 18:40:40 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	quot_tok_len(char *input)
{
	int	i;

	i = 0;
	if (input && *input == '\'')
	{
		if (input[i + 1] && input[i + 1] == '\'')
			return (2);
		i++;
		while (input && input[i] && input[i] != '\'')
			i++;
		return (i);
	}
	return (i);
}

char	*joined_merger(char *str1, char *str2, int flag)
{
	char	*result;
	char	*trimm_1;
	char	*trimm_2;

	if (flag == 1)
		trimm_1 = trimm_quotes(str1);
	else
		trimm_1 = str1;
	trimm_2 = trimm_quotes(str2);
	result = ft_strjoin_gnl(trimm_1, trimm_2);
	free(trimm_2);
	return (result);
}
