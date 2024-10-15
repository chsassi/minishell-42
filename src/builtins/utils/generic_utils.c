/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:02:32 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 21:02:35 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fd(int fd)
{
	if (fd != -1)
		close(fd);
}

void	handle_pipe_dups(t_all *pAll, t_shell *pShell)
{
	close_fd(pShell->fd_in);
	close_fd(pShell->fd_out);
	if (pShell->fd_in == -1 && pShell->cmd_idx > 0)
		dup2(pAll->arr_pipe[pShell->cmd_idx - 1][0], STDIN_FILENO);
	if (pShell->fd_out == -1 && pShell->cmd_idx < pAll->cmd_nbr - 1)
		dup2(pAll->arr_pipe[pShell->cmd_idx][1], STDOUT_FILENO);
}

int	count_pars(t_pars *p)
{
	int	n;

	n = 0;
	while (p)
	{
		n++;
		p = p->next;
	}
	return (n);
}
