/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:40:05 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/01 13:40:07 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	input_check(char *input, t_env **env)
{
	if (!input)
	{
		write(1, "exit\n", 6);
		free_env_list(env);
		return (0);
	}
	return (1);
}

void	check_input_loop(t_all *pAll, t_shell *shell)
{
	pid_t	pid;

	exec_redirection(pAll);
	if (pAll->cmd_nbr > 1)
	{
		pid = fork();
		//check_cmd_order();
		if (pid == 0)
		{
			run_exec(*pAll->env, shell->cmd, true);
			//check free
			exit(pAll->status_code);
		}
	}
	else
		run_exec(*pAll->env, shell->cmd, false);
}

int	process_input(t_all *pAll)
{
	int			**pipex;
	int			i;

	pAll->shell = parse_input(pAll->shell.input, pAll->env);
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
		pAll->shell.pipe = pipex[i];
		check_input_loop(pAll, &(pAll->shell));
	}
	waitpid(-1, pAll->status_code, 0);
	if (WIFEXITED(pAll->status_code))
		g_exit = WEXITSTATUS(pAll->status_code);
	else if (WIFSIGNALED(pAll->status_code))
		g_exit = pAll->status_code;

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
		ptr.shell.input = readline("minishell> ");
		if (!input_check(ptr.shell.input, env))
			exit (0);
		// if (!input)
		// {
		// 	write(1, "exit\n", 5);
		// 	free_env_list(env);
		// 	exit(0);
		// }
		if (!process_input(&ptr))
		{
			free(ptr.shell.input);
			continue ;
		}
		if (ft_strlen(ptr.shell.input) > 0)
			add_history(ptr.shell.input);
		free(ptr.shell.input);
	}
}
