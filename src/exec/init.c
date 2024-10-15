/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:40:05 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/13 14:52:07 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_input_loop(t_all *pAll, t_shell *pShell)
{
	pid_t	pid;

	if (!exec_redirection(pAll, pShell))
		return ;
	if (pShell->fd_in != -1)
		dup2(pShell->fd_in, STDIN_FILENO);
	if (pShell->fd_out != -1)
		dup2(pShell->fd_out, STDOUT_FILENO);
	if (pAll->cmd_nbr > 1)
	{
		pid = fork();
		if (pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			handle_pipe_dups(pAll, pShell);
			close_pipes_loop(pAll);
			run_exec(pAll, pShell, true);
			printf("x\n");
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

	if (!exec_heredocs(pAll))
		return (free(pAll->arr_pipe), 0);
	if (pAll->cmd_nbr == 0)
		return (1);
	pAll->arr_pipe = ft_calloc(pAll->cmd_nbr, sizeof(int *));
	if (!pAll->arr_pipe)
		return (free_all(pAll, true, 1), 0);
	i = -1;
	ptr = pAll->shell;
	while (++i < pAll->cmd_nbr)
	{
		signal(SIGINT, print_nl_on_sigint);
		pAll->arr_pipe[i] = init_pipes(pAll);
		check_input_loop(pAll, ptr);
		ptr = ptr->next;
		restore_fds(pAll);
	}
	close_pipes_loop(pAll);
	return (1);
}

int	process_input(t_all *pAll)
{
	int		status;
	t_shell	*ptr;

	if (!pAll->shell)
		return (0);
	pAll->status_code = 0;
	run_all_cmds(pAll);
	ptr = pAll->shell;
	while (wait(&status) != -1)
	{
		if (WIFEXITED(status))
			pAll->status_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			g_exit = WTERMSIG(status);
			set_status_from_sig(pAll, g_exit);
		}
	}
	while (ptr)
	{
		if (ptr->last_heredoc)
			unlink(ptr->last_heredoc);
		ptr = ptr->next;
	}
	return (free_shell(pAll), 1);
}

bool	process_loop(t_all *pAll)
{
	set_status_from_sig(pAll, g_exit);
	if (ft_strlen(pAll->input) == 0 && pAll->status_code == 130)
	{
		free(pAll->input);
		return (false);
	}
	pAll->shell = parsing(pAll);
	if (!process_input(pAll))
	{
		free(pAll->input);
		return (false);
	}
	if (ft_strlen(pAll->input) > 0)
		add_history(pAll->input);
	return (true);
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
		g_exit = -42;
		ptr.cmd_nbr = 0;
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handle_sigint);
		ptr.input = readline("minishell> ");
		input_check(&ptr);
		if (!process_loop(&ptr))
			continue ;
		free(ptr.input);
	}
}
