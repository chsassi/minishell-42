/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:36:28 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/11 16:48:52 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all	*all_init(t_pars *parser, char *input)
{
	t_all	*new;

	new = (t_all *)malloc(sizeof(t_all));
	if (!new)
		return (NULL);
	new->input = input;
	new->shell = shell_init(parser);
	new->env = NULL;
	new->arr_pipe = NULL;
	new->cmd_nbr = 0;
	new->restore_fd_in = -1;
	new->restore_fd_out = -1;
	new->status_code = 0;
	return (new);
}