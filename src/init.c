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

int	process_input(char *input, t_env **env, int fd_in, int fd_out)
{
	t_all		*all;
	t_shell		*shell;
	int			**pipex;
	int			i;
	pid_t		process;

	(void)shell;
	(void)process;
	all = parse_input(input, env);
	if (!all)
		return (/*free*/0);
	//check sintassi
	exec_heredocs(all->shell);
	pipex = ft_calloc(all->cmd_nbr, sizeof(int *));
	if (!pipex)
		return (/*free*/0);
	i = -1;
	while (++i < all->cmd_nbr)
	{
		// check su fd se c'e' un'unica pipe, se c'e' piu di un comando e, se si, quale id sono
		//in base a questo devo reindirizzare l'output delle pipe chiudendole e rinizializzandole
		pipex[i] = ft_calloc(2, sizeof(int));
		if (pipe(pipex[i]) == -1)
			return (/*free*/0);
		all->shell->pipe = pipex[i];
		check_input_loop(all, all->shell);
	}
	return (restore_fds(all), /*free*/ 1);
}

void	minishell_loop(char *input, t_env *env)
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
		input = readline("minishell> ");
		if (!input)
		{
			write(1, "exit\n", 5);
			free_env_list(env);
			exit(0);
		}
		if (!process_input(input, &env, fd))
		{
			free(input);
			continue ;
		}
		if (ft_strlen(input) > 0)
			add_history(input);
		free(input);
	}
}
