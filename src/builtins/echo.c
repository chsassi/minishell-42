/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:52:27 by chsassi           #+#    #+#             */
/*   Updated: 2024/07/30 10:19:00 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "minishell.h"

void run_echo(t_all *pAll)
{
	int	i;
	int	nl;

	i = 1;
	nl = 1;
	if (pAll->prompt[1] && !ft_strcmp(pAll->prompt[1], "-n"))
	{
		nl = 0;
		i = 2;
	}
	while (pAll->prompt[i])
	{
		printf("%s", pAll->prompt[i]);
		if (pAll->prompt[i + 1])
			printf(" ");
		i++;
	}
	if (nl)
		printf("\n");
}
