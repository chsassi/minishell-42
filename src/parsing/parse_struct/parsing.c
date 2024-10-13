/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:04:53 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/12 18:40:40 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_trash(t_phelp *ptr)
{
	clear_parse(ptr->parser);
	free(ptr->tokens);
	free(ptr->input_exp);
}

t_shell	*parsing(t_all *pAll)
{
	t_phelp	ptr;
	t_shell	*shell;

	shell = NULL;
	ptr = (t_phelp){0};
	ptr.input_exp = expansion(pAll, *pAll->env);
	ptr.mtx = create_mtx(ptr.input_exp);
	if (!ptr.mtx)
		return (free_trash(&ptr), NULL);
	ptr.tokens = token_arr(ptr.mtx);
	ptr.parser = parse_struct_init(ptr.input_exp, ptr.mtx, ptr.tokens);
	if (!check_all_errors(ptr.parser))
	{
		ft_putstr_fd("Syntax error!\n", 2);
		pAll->status_code = 2;
		return (free_trash(&ptr), NULL);
	}
	pAll->cmd_nbr = count_pipes(ptr.parser);
	shell = shell_init(&ptr.parser);
	return (free_trash(&ptr), shell);
}
