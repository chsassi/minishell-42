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
	int	i;
	int	nl;

	i = 1;
	nl = 1;
	if (pShell->cmd[1] && !ft_strcmp(pShell->cmd[1], "-n"))
	{
		nl = 0;
		i = 2;
	}
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
