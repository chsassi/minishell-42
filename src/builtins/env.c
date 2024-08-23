/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:17:57 by chsassi           #+#    #+#             */
/*   Updated: 2024/08/19 16:39:51 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_env(t_all *pAll)
{
	char	*error;
	error = pAll->prompt[1];

	if (error)
		printf("env: '%s': no such file or directory", error);
	else
	{
		while (pAll->envp)
		{
			printf("%s=%s\n", pAll->envp->var, pAll->envp->content);
			pAll = pAll->envp->next;
		}
	}
}
