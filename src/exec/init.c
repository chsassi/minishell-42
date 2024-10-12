/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:40:05 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 18:40:20 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_input_loop(t_all *pAll, t_shell *pShell)
{
	pid_t	pid;

	exec_redirection(pAll);
	if (pAll->cmd_nbr > 1)
	{
		pid = fork();
		if (pid == 0)
		{
			run_exec(pAll, pShell, true);
			free_all(pAll, true, pAll->status_code);
		}
	}
	else
		run_exec(pAll, pShell, false);
}

int	run_all_cmds(t_all *pAll)
{
	t_shell	*ptr;
	int		i;

	pAll->arr_pipe = ft_calloc(pAll->cmd_nbr, sizeof(int *));
	if (!pAll->arr_pipe)
		return (free_all(pAll, true, 1), 0);
	exec_heredocs(pAll);
	i = -1;
	ptr = pAll->shell;
	while (++i < pAll->cmd_nbr)
	{
		pAll->arr_pipe[i] = init_pipes(pAll);
		check_input_loop(pAll, ptr);
		ptr = ptr->next;
	}
	close_pipes_loop(pAll);
	return (1);
}

int	process_input(t_all *pAll)
{
	int	status;

	if (!pAll->shell)
		return (0);
	run_all_cmds(pAll);
	while (waitpid(-1, &status, 0) != -1)
	{
		if (WIFEXITED(status))
			pAll->status_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			set_status_from_sig(pAll, WTERMSIG(status));
	}
	return (restore_fds(pAll), 1);
}

void	minishell_loop(t_env *env)
{
	t_all	ptr;

	ptr = (t_all){0};
	ptr.env = &env;
	ptr.restore_fd_in = dup(STDIN_FILENO);
	ptr.restore_fd_out = dup(STDOUT_FILENO);
	while (1)
	{
		ptr.cmd_nbr = 0;
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handle_sigint);
		ptr.input = readline("minishell> ");
		input_check(&ptr);
		free_shell(&ptr);
		ptr.shell = parsing(&ptr);
		if (!process_input(&ptr))
		{
			free(ptr.input);
			continue ;
		}
		if (ft_strlen(ptr.input) > 0)
			add_history(ptr.input);
		free(ptr.input);
	}
}
