/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:55:25 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/04 19:33:36 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_pars	*new_parse_node(char **mtx, int i, int tok)
{
	t_pars	*new;

	new = (t_pars *)malloc(sizeof(t_pars));
	if (!new)
		return (NULL);
		
		new->str = ft_strdup(mtx[i]);
		new->type = tok;
	new->next = NULL;
	return (new);
}

// t_pars *init_parser(char *input, char **mtx, int *array)
// {
// 	int		i;
// 	int		quote_number;
// 	t_pars	*parser;

// 	i = 0;
// 	parser = NULL;
// 	quote_number = quote_tokens(array, input);
// 	while (mtx[i] != '\0')
// 	{
// 		if (array[i] == DOUBLE_QUOTE || array[i] == QUOTE || array[i] == WORD)
// 		{
			
// 		}
// 		if (!parser)
// 			parser = new_parse_node(mtx[i], array[i]);
// 		i++;
// 	}
// 	return (parser);
// }


t_pars	*parse_struct_init(char *input, char **mtx, int *token)
{
	t_pars	*parsing;
	int		*merge;
	int		i;

	parsing = NULL;
	merge = process_arr_merger(input, mtx);
	i = 0;
	while (mtx[i] != NULL)
	{
		if (!parsing == NULL)
			parsing = new_parse_node(mtx, i, token[i]);
	}
	return (parsing)
}