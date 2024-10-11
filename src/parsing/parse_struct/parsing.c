/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:04:53 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/11 17:14:56 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_shell	*parsing(char *input, char **env)
{
	t_phelp ptr;
	
	ptr = (t_phelp){0};
	ptr.input_exp = expansion(input, env)
}