/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:55:15 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 18:40:20 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	restore_fds(t_all *pAll)
{
	dup2(pAll->restore_fd_in, STDIN_FILENO);
	dup2(pAll->restore_fd_out, STDOUT_FILENO);
	close(pAll->restore_fd_in);
	close(pAll->restore_fd_out);
	pAll->restore_fd_in = dup(STDIN_FILENO);
	pAll->restore_fd_out = dup(STDOUT_FILENO);
}

int	handle_redirection_open(char *type, char *file)
{
	int	redirect_fd;

	if (!ft_strcmp(type, REDIRECT_IN))
		redirect_fd = open(file, O_RDONLY);
	else if (!ft_strcmp(type, REDIRECT_OUT))
		redirect_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (!ft_strcmp(type, REDIRECT_APPEND))
		redirect_fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		return (-1);
	return (redirect_fd);
}

int	handle_redirection(t_all *pAll, char *type, char *file)
{
	const int	redirect_fd = handle_redirection_open(type, file);

	if (redirect_fd == -1)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		pAll->status_code = 1;
		return (0);
	}
	if (!ft_strcmp(type, REDIRECT_IN))
	{
		if (pAll->shell->fd_in != -1)
			close(pAll->shell->fd_in);
		pAll->shell->fd_in = redirect_fd;
		return (1);
	}
	if (pAll->shell->fd_out != -1)
		close(pAll->shell->fd_out);
	pAll->shell->fd_out = redirect_fd;
	return (1);
}

bool	exec_redirection(t_all *pAll, t_shell *pShell)
{
	int	i;

	i = 0;
	while (pShell->redirects && pShell->redirects[i])
	{
		if (!ft_strcmp(pShell->redirects[i], REDIRECT_IN)
			|| !ft_strcmp(pShell->redirects[i], REDIRECT_OUT)
			|| !ft_strcmp(pShell->redirects[i], REDIRECT_APPEND))
		{
			if (!handle_redirection(pAll, pShell->redirects[i],
					pShell->redirects[i + 1]))
				return (false);
		}
		i++;
	}
	if (pShell->last_heredoc)
	{
		pShell->fd_in = open(pShell->last_heredoc, O_RDONLY);
		if (pShell->fd_in == -1)
			return (false);
	}
	return (true);
}
