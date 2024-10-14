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

int	newline_check(t_shell *pShell, int i, bool *nl)
{
	int	j;

	while (pShell->cmd[i] && !ft_strncmp(pShell->cmd[i], "-", 1)
		&& ft_strlen(pShell->cmd[i]) > 1)
	{
		j = 1;
		while (pShell->cmd[i][j] == 'n')
			j++;
		if (!pShell->cmd[i][j])
		{
			*nl = false;
			i++;
		}
		else
			break ;
	}
	return (i);
}

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
