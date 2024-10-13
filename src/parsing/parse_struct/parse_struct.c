/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:55:25 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/12 18:40:40 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_pars	*parse_struct_init(char *input, char **mtx, int *token)
{
	t_pars	*head;
	t_pars	*parsing;
	int		*merge;
	int		i;

	i = 0;
	if (ft_strlen(*mtx) == 0)
		merge = NULL;
	else
		merge = process_arr_merger(input, mtx);
	if (!token)
		return (free_mtx(mtx), NULL);
	head = new_parse_node(mtx, &i, token[i], merge);
	while (mtx[i] != NULL)
	{
		parsing = new_parse_node(mtx, &i, token[i], merge);
		add_back_parse(&head, parsing);
	}
	free(merge);
	free_mtx(mtx);
	return (head);
}
