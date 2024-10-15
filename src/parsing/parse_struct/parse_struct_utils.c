/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:05:46 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 19:05:48 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	free_parse_node(t_pars *parser)
{
	if (!parser)
		return ;
	free(parser->str);
	if (parser->prev)
		parser->prev->next = NULL;
	if (parser->next)
		parser->next->prev = NULL;
	parser->next = NULL;
	parser->prev = NULL;
	free(parser);
}

void	clear_parse(t_pars *parser)
{
	t_pars	*tmp;

	tmp = NULL;
	while (parser)
	{
		tmp = parser->next;
		free_parse_node(parser);
		parser = tmp;
	}
}
