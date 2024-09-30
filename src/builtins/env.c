/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:17:57 by chsassi           #+#    #+#             */
/*   Updated: 2024/09/23 10:37:50 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*bin_env(t_env *env)
{
	t_env	*current;

	current = env;
	while (current)
	{
		print_env(current);
		current = current->next;
	}
	g_exit = 0;
	return (env);
}
