/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:52:27 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 18:40:20 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bin_echo(t_all *pAll, t_shell *pShell)
{
	int		i;
	bool	nl;

	i = 1;
	nl = true;
	i = newline_check(pShell, i, &nl);
	while (pShell->cmd[i])
	{
		printf("%s", pShell->cmd[i]);
		if (pShell->cmd[i + 1])
			printf(" ");
		i++;
	}
	if (nl)
		printf("\n");
	pAll->status_code = 0;
}
