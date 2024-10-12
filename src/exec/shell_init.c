/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:02:04 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/12 15:02:33 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_pipes(t_pars *parser)
{
	int		i;
	bool	atleast_one;

	i = 0;
	atleast_one = false;
	while (parser)
	{
		if (parser->type == PIPE_LINE)
			i += 1;
		parser = parser->next;
		atleast_one = true;
	}
	if (i == 0 && !atleast_one)
		return (0);
	return (i + 1);
}

t_pars	*free_parse_until_pipe(t_pars *parser)
{
	t_pars	*node;
	t_pars	*tmp;

	node = parser;
	while (node && node->type != PIPE_LINE)
	{
		tmp = node->next;
		free_parse_node(node);
		node = tmp;
	}
	if (node && node->type == PIPE_LINE)
	{
		tmp = node->next;
		free_parse_node(node);
		node = tmp;
	}
	return (node);
}

t_shell	*shell_init(t_pars **parser)
{
	t_shell	*shell;
	t_pars	*ptr;

	shell = NULL;
	while (*parser)
	{
		ptr = *parser;
		shell_add_back(&shell, new_shell_node(&ptr));
		ptr = free_parse_until_pipe(ptr);
		*parser = ptr;
	}
	return (shell);
}
