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

t_shell	*parsing(char *input, char **env)
{
	t_phelp	ptr;
	t_shell	*shell;

	shell = NULL;
	ptr = (t_phelp){0};
	ptr.input_exp = expansion(input, env);
	ptr.mtx = create_mtx(ptr.input_exp);
	if (!ptr.mtx)
		return (free(input), NULL);
	else
	{
		ptr.tokens = token_arr(ptr.mtx);
		ptr.parser = parse_struct_init(ptr.input_exp, ptr.mtx, ptr.tokens);
		if (!check_all_errors(ptr.parser))
		{
			free_trash(ptr.parser, ptr.tokens, ptr.input_exp);
			return (NULL);
		}
	}
	shell = shell_init(ptr.parser);
	clear_parse(ptr.parser);
	free(ptr.tokens);
	free(ptr.input_exp);
	return (shell);
}
