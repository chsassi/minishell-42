/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:53:25 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 18:53:28 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_shell(t_all *pAll)
{
	t_shell	*shell;
	t_shell	*next;

	shell = pAll->shell;
	while (shell)
	{
		next = shell->next;
		free_mtx(shell->cmd);
		free_mtx(shell->redirects);
		if (shell->fd_in != -1)
			close(shell->fd_in);
		if (shell->fd_in != -1)
			close(shell->fd_out);
		free(shell->last_heredoc);
		free(shell);
		shell = next;
	}
	pAll->shell = NULL;
}

void	free_all(t_all *pAll, bool should_exit, int status_code)
{
	free(pAll->input);
	free_env_list(*pAll->env);
	free_shell(pAll);
	close_pipes_loop(pAll);
	close(pAll->restore_fd_in);
	close(pAll->restore_fd_out);
	if (should_exit)
		exit(status_code);
}
