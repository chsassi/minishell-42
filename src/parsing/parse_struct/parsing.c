/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:04:53 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/11 20:32:53 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_trash(t_pars *parser, int *tokens, char *input)
{
			clear_parse(parser);
			free(tokens);
			free(input);
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
		return (free(pAll->input), NULL);
	else
	{
		ptr.tokens = token_arr(ptr.mtx);
		ptr.parser = parse_struct_init(ptr.input_exp, ptr.mtx, ptr.tokens);
		if (!check_all_errors(ptr.parser))
			return (free_trash(ptr.parser, ptr.tokens, ptr.input_exp), NULL);
		pAll->cmd_nbr = count_pipes(ptr.parser);
	}
	shell = shell_init(ptr.parser);
	return (clear_parse(ptr.parser), free(ptr.tokens),
		free(ptr.input_exp), shell);
}
