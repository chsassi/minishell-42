/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:40:05 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/07 16:43:50 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_input_loop(t_all *pAll)
{
	pid_t	pid;

	exec_redirection(pAll);
	if (pAll->cmd_nbr > 1)
	{
		pid = fork();
		if (pid == 0)
		{
			run_exec(*pAll->env, pAll->shell->cmd, true);
			//check free
			exit(pAll->status_code);
		}
	}
	else
		run_exec(*pAll->env, pAll->shell->cmd, false);
}

int	process_input(t_all *pAll)
{
	int			**pipex;
	int			status;
	int			i;

	pAll->shell = parse_input(pAll->shell->input, pAll->env);
	if (!pAll)
		return (/*free*/0);
	pipex = ft_calloc(pAll->cmd_nbr - 1, sizeof(int *));
	if (!pipex)
		return (free(pipex), 0);
	//check sintassi
	exec_heredocs(&pAll);
	i = -1;
	while (++i < pAll->cmd_nbr)
	{
		// check su fd se c'e' un'unica pipe, se c'e' piu di un comando e, se si, quale id sono
		//in base a questo devo reindirizzare l'output delle pipe chiudendole e rinizializzandole
		pipex[i] = ft_calloc(2, sizeof(int));
		if (pipe(pipex[i]) == -1)
			return (/*free*/0);
		pAll->shell->pipe = pipex[i];
		check_input_loop(pAll);
	}
	i = 0;
	close_pipes_loop(pipex, pAll->cmd_nbr);
	waitpid(-1, &status, 0);
	if (WIFEXITED(status))
		pAll->status_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		pAll->status_code = WTERMSIG(status);
	return (restore_fds(pAll), /*free*/ 1);
}

void	minishell_loop(t_env *env)
{
	t_all	ptr;
	int		fd[2];

	ptr = (t_all){0};
	ptr.env = &env;
	ptr.restore_fd_in = dup(STDIN_FILENO);
	ptr.restore_fd_out = dup(STDOUT_FILENO);
	while (1)
	{

		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handle_sigint);
		ptr.shell->input = readline("minishell> ");
		input_check(ptr.shell->input);
		if (!process_input(&ptr))
		{
			free(ptr.shell->input);
			continue ;
		}
		if (ft_strlen(ptr.shell->input) > 0)
			add_history(ptr.shell->input);
		free(ptr.shell->input);
	}
}
