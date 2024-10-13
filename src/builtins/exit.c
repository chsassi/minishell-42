/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:17:57 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 18:40:20 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_numeric(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (str[i] == '+' && !ft_isdigit(str[i + 1]))
			return (false);
	}
	return (true);
}

int	check_exit_params(t_all *pAll, t_shell *pShell)
{
	if (pShell->args_nbr > 2)
		return (ft_putstr_fd("bash: exit: too many arguments\n", 2), 0);
	if (pShell->cmd[1] && !is_numeric(pShell->cmd[1]))
	{
		ft_putstr_fd("bash: exit: ", 2);
		ft_putstr_fd(pShell->cmd[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		pAll->status_code = 2;
		if (pShell->args_nbr == 2)
			free_all(pAll, true, pAll->status_code);
		return (0);
	}
	return (1);
}

void	bin_exit(t_all *pAll, t_shell *pShell)
{
	if (!check_exit_params(pAll, pShell))
		return ;
	if (pShell->args_nbr == 1)
	{
		write(1, "exit\n", 5);
		free_all(pAll, true, pAll->status_code);
	}
	if ((pShell->args_nbr == 2 && is_numeric(pShell->cmd[1])))
	{
		pAll->status_code = ft_atoi(pShell->cmd[1]);
		write(1, "exit\n", 5);
		free_all(pAll, true, pAll->status_code);
	}
}
