/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:07:24 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/12 18:40:40 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_redirect(int type)
{
	if (type == REDIR_IN || type == REDIR_OUT || type == HERE_DOC
		|| type == DREDIR_OUT)
		return (1);
	return (0);
}

int	len_red_mtx(t_pars *parser)
{
	int	i;

	i = 0;
	while (parser)
	{
		if (is_redirect(parser->type))
		{
			i += 2;
			parser = parser->next;
		}
		if (parser)
			parser = parser->next;
	}
	return (i);
}

void	reorg_struct(t_pars **parser, char **mtx, int *i)
{
	t_pars	*tmp;

	tmp = *parser;
	if ((*parser)->prev != NULL)
		(*parser)->prev->next = (*parser)->next->next;
	if ((*parser)->next->next != NULL)
		(*parser)->next->next->prev = (*parser)->prev;
	mtx[(*i)] = ft_strdup((*parser)->str);
	(*parser) = (*parser)->next;
	(*i)++;
	free(tmp->str);
	tmp->next = NULL;
	tmp->prev = NULL;
	free(tmp);
	tmp = *parser;
	mtx[(*i)] = ft_strdup((*parser)->str);
	(*parser) = (*parser)->next;
	free(tmp->str);
	tmp->next = NULL;
	tmp->prev = NULL;
	free(tmp);
}

char	**red_mtx(t_pars **parser)
{
	char	**mtx;
	int		len;
	int		i;
	t_pars	*tmp;

	i = 0;
	tmp = *parser;
	len = len_red_mtx(*parser);
	mtx = (char **)ft_calloc(sizeof(char *), (len + 1));
	if (!mtx)
		return (NULL);
	while (tmp && tmp->type != PIPE_LINE)
	{
		if (is_redirect(tmp->type))
		{
			reorg_struct(&tmp, mtx, &i);
			*parser = tmp;
			i++;
			continue ;
		}
		if (tmp != NULL)
			tmp = tmp->next;
	}
	return (mtx);
}

char	**cmd_mtx(t_pars *parser)
{
	int		n;
	t_pars	*tmp;
	char	**mtx;

	n = 0;
	tmp = parser;
	while (tmp)
	{
		tmp = tmp->next;
		n++;
	}
	mtx = (char **)ft_calloc((n + 1), sizeof(char *));
	if (!mtx)
		return (NULL);
	n = 0;
	while (parser && parser->type != PIPE_LINE)
	{
		mtx[n] = parser->str;
		parser->str = NULL;
		parser = parser->next;
		n++;
	}
	return (mtx);
}
