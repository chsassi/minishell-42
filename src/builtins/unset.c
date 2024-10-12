/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:17:57 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 18:40:20 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	unset_check_head(t_all *pAll, char *variable)
{
	t_env	*tmp;

	if (!pAll->env)
		return (true);
	if (!is_valid_var("unset", variable))
		return (false);
	if ((*pAll->env)->var && !ft_strcmp((*pAll->env)->var, variable))
	{
		tmp = *pAll->env;
		*pAll->env = (*pAll->env)->next;
		free_env_node(tmp);
	}
	return (true);
}

static bool	unset_check_all(t_all *pAll, char *variable)
{
	t_env	*tmp;
	t_env	*next;

	if (!is_valid_var("unset", variable))
		return (false);
	tmp = *pAll->env;
	while (tmp)
	{
		next = tmp->next;
		if (next && !ft_strcmp(next->var, variable))
		{
			tmp->next = next->next;
			free_env_node(next);
		}
		tmp = tmp->next;
	}
	return (true);
}

t_env	*bin_unset(t_all *pAll, t_shell *pShell)
{
	int		i;
	bool	check;

	if (!pAll->env)
		return (NULL);
	i = 0;
	check = true;
	while (pShell->cmd && pShell->cmd[++i])
	{
		check = check && unset_check_head(pAll, pShell->cmd[i]);
		check = check && unset_check_all(pAll, pShell->cmd[i]);
	}
	pAll->status_code = 0;
	if (!check)
		pAll->status_code = 1;
	return (NULL);
}
