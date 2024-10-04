/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:55:15 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/01 11:55:16 by chsassi          ###   ########.fr       */
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

int	handle_redirection(t_all *pAll, char *type, char *file)
{
	int	redirect_fd;

	if (!ft_strcmp(type, REDIRECT_IN))
		redirect_fd = open(file, O_RDONLY);
	else if (!ft_strcmp(type, REDIRECT_OUT))
		redirect_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (!ft_strcmp(type, REDIRECT_APPEND))
		redirect_fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		return (0);
	if (redirect_fd < 0)
		return (ft_putstr_fd("bash: fd: Bad file descriptor\n", 2), 0);
	if (!ft_strcmp(type, REDIRECT_IN))
		pAll->shell->fd_in = redirect_fd;
	else
		pAll->shell->fd_out = redirect_fd;

	return (1);
}

void	exec_redirection(t_all *pAll)
{
	int	i;

	i = 0;
	while (pAll->shell->redirects && pAll->shell->redirects[i])
	{
		if (!ft_strcmp(pAll->shell->redirects[i], REDIRECT_IN)
			|| !ft_strcmp(pAll->shell->redirects[i], REDIRECT_OUT)
			|| !ft_strcmp(pAll->shell->redirects[i], REDIRECT_APPEND))
		{
			handle_redirection(pAll, pAll->shell->redirects[i], pAll->shell->redirects[i + 1]);
			pAll->shell->redirects[i] = NULL;
			break ;
		}
		i++;
	}
	if (pAll->shell->fd_in != -1)
		dup2(pAll->shell->fd_in, STDIN_FILENO);
	if (pAll->shell->fd_out != -1)
		dup2(pAll->shell->fd_out, STDOUT_FILENO);
}
