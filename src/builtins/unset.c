/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:17:57 by chsassi           #+#    #+#             */
/*   Updated: 2024/07/30 10:19:00 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*bin_unset(t_all *pAll, t_shell *pShell)
{
	t_env	*tmp;
	t_env	**original_head;

	if (!pAll->env || !*pAll->env)
		return (*pAll->env);
	original_head = pAll->env;
	while (*pAll->env && ft_strcmp((*pAll->env)->var, pShell->cmd[1]))
		pAll->env = &((*pAll->env)->next);
	if (*pAll->env)
	{
		tmp = *pAll->env;
		*pAll->env = (*pAll->env)->next;
		free_env_node(tmp);
	}
	g_exit = 0;
	return (*original_head);
}
