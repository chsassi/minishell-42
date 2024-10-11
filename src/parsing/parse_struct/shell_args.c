/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:07:24 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/11 20:36:17 by brulutaj         ###   ########.fr       */
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

char	**red_mtx(t_pars *parser)
{
	char	**mtx;
	int		len;
	int		i;

	i = 0;
	len = len_red_mtx(parser);
	mtx = (char **)malloc(sizeof(char *) * (len + 1));
	if (!mtx)
		return (NULL);
	while (parser && parser->type != PIPE_LINE)
	{
		if (is_redirect(parser->type))
		{
			reorg_struct(&parser, mtx, &i);
			i++;
			continue ;
		}
		if (parser != NULL)
			parser = parser->next;
	}
	mtx[i] = NULL;
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
	mtx = (char **)malloc((n + 1) * sizeof(char *));
	n = 0;
	while (parser && parser->type != PIPE_LINE)
	{
		mtx[n] = ft_strdup(parser->str);
		parser = parser->next;
		n++;
	}
	mtx[n] = NULL;
	return (mtx);
}
