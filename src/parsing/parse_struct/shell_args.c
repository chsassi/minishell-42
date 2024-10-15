/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:07:24 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/12 20:52:17 by brulutaj         ###   ########.fr       */
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

t_pars	*reorg_struct(t_pars *curr_redirect, char **mtx, int *i)
{
	mtx[(*i)++] = ft_strdup(curr_redirect->str);
	curr_redirect = curr_redirect->next;
	mtx[(*i)++] = ft_strdup(curr_redirect->str);
	curr_redirect = curr_redirect->next;
	return (curr_redirect);
}

char	**red_mtx(t_pars **parser)
{
	const int	len = len_red_mtx(*parser);
	char		**mtx;
	int			i;
	t_pars		*tmp;

	tmp = *parser;
	mtx = (char **)ft_calloc(sizeof(char *), (len + 1));
	if (!mtx)
		return (NULL);
	i = 0;
	while (tmp && tmp->type != PIPE_LINE)
	{
		if (is_redirect(tmp->type))
		{
			tmp = reorg_struct(tmp, mtx, &i);
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

	tmp = parser;
	n = 0;
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
		if (parser->type == -1)
		{
			mtx[n++] = parser->str;
			parser->str = NULL;
		}
		parser = parser->next;
	}
	return (mtx);
}
