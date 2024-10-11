/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:02:04 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/11 16:05:57 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_pipes(t_pars *parser)
{
	int	i;

	i = 0;
	while (parser)
	{
		if (parser->type == PIPE_LINE)
			i += 1;
		parser = parser->next;
	}
	return (i);
}

t_shell	*shell_init(t_pars *parser)
{
	t_shell	*shell;
	t_pars	*ptr;

	shell = NULL;
	while (parser)
	{
		ptr = parser;
		shell_add_back(&shell, new_shell_node(ptr));
		while (ptr && ptr->type != PIPE_LINE)
			ptr = ptr->next;
		if (ptr && ptr->type == PIPE_LINE)
			ptr = ptr->next;
		parser = ptr;
	}
	return (shell);
}
