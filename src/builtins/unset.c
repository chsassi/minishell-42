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

t_env	*bin_unset(t_all *pAll, t_shell *pShell)
{
	int		i;
	bool	check;
	bool	is_valid;

	if (!pAll->env)
		return (NULL);
	i = 0;
	check = true;
	while (pShell->cmd && pShell->cmd[++i])
	{
		is_valid = is_valid_var("unset", pShell->cmd[i]);
		check = check && is_valid;
		if (!is_valid)
			continue ;
		if (!unset_check_head(pAll, pShell->cmd[i]))
			check = false;
		if (!unset_check_all(pAll, pShell->cmd[i]))
			check = false;
	}
	pAll->status_code = 0;
	if (!check)
		pAll->status_code = 1;
	return (NULL);
}
