/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <chsassi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:17:57 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 18:40:20 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*bin_env(t_all *pAll)
{
	t_env	*current;

	current = *pAll->env;
	while (current)
	{
		print_env(current);
		current = current->next;
	}
	pAll->status_code = 0;
	return (*pAll->env);
}
