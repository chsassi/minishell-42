/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:55:25 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/12 14:35:10 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_pars	*new_parse_node(char **mtx, int *i, int tok, int *arr)
{
	t_pars	*new;

	new = (t_pars *)ft_calloc(1, sizeof(t_pars));
	if (!new)
		return (NULL);
	new->str = merge_string(arr, mtx, i);
	new->type = tok;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_pars	*last_parse(t_pars *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	add_back_parse(t_pars **lst, t_pars *new)
{
	t_pars	*tmp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = last_parse(*lst);
	tmp->next = new;
	new->prev = tmp;
}

void	clear_parse(t_pars *parser)
{
	t_pars	*tmp;

	tmp = NULL;
	while (parser)
	{
		tmp = parser;
		parser = parser->next;
		free(tmp->str);
		tmp->next = NULL;
		tmp->prev = NULL;
		free(tmp);
	}
}

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
		return (NULL);
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
