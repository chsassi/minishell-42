/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:17:57 by chsassi           #+#    #+#             */
/*   Updated: 2024/07/30 10:19:00 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_exit_params(t_shell *pShell)
{
	if (pShell->cmd[2])
		return (ft_putstr_fd("bash: exit: too many arguments\n", 2), 0);
	if (pShell->cmd[1] && !is_numeric(pShell->cmd[1]))
	{
		ft_putstr_fd("bash: exit: ", 2);
		ft_putstr_fd(pShell->cmd[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		g_exit = 2;
		return (0);
	}
	return (1);
}

void	bin_exit(t_all *pAll, t_shell *pShell)
{
	if (!check_exit_params(pShell))
		return ;
	if (!pShell->cmd[1])
	{
		write(1, "exit\n", 5);
		free_env_list(*pAll->env);
		//free
		exit(pAll->status_code);
	}
	if (pShell->cmd[1] && is_numeric(pShell->cmd[1]))
	{
		pAll->status_code = ft_atoi(pShell->cmd[1]);
		write(1, "exit\n", 5);
		free_env_list(*pAll->env);
		//free
		exit(pAll->status_code);
	}
}
