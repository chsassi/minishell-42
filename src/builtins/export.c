/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:17:57 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 18:40:20 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//da fare join con lo spazio
void	bin_export(t_all *pAll, t_shell *pShell)
{
	t_env	*current;
	int		i;

	if (!pShell->cmd[1])
	{
		current = *pAll->env;
		while (current)
		{
			print_export(current);
			current = current->next;
		}
		return ;
	}
	i = 0;
	while (pShell->cmd[++i])
		export_var(pAll, pShell->cmd[i]);
}
