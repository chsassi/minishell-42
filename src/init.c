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

void	check_redirection(/*t_shell *ptr */char **args, int fd[2])
{
	int	i;

	i = 0;
	while (ptr->redirects && ptr->redirects[i])
	{
		if (!ft_strcmp(ptr->redirects[i], REDIRECT_IN)
			|| !ft_strcmp(ptr->redirects[i], REDIRECT_OUT)
			|| !ft_strcmp(ptr->redirects[i], REDIRECT_APPEND))
		{
			handle_redirection(ptr->redirects[i], ptr->redirects[i + 1], fd);
			ptr->redirects[i] = NULL;
			break ;
		}
		i++;
	}
}

int	process_input(char *input, t_env **env, int fd[2])
{
	char	**args;
	int		**pipex;
	int		i;
	pid_t	process;

	args = ft_split(input, ' ');
	if (!args || !args[0])
		return (free_mtx(args), 0);
	//check sintassi
	run_all_heredoc();
	pipex = ft_calloc(cmd_nbr, sizeof(int *));
	i = -1;
	while (++i < cmd_nbr)
	{
		pipex[i] = ft_calloc(2, sizeof(int));
		if (pipe(pipex[i]) == -1)
		{
			// free di tutto quello che ho allocato finora
			return (0);
		}
		check_redirection(args, fd);
		if (cmd_nbr > 1)
		{
			process = fork();
			if (process == 0)
			{
				run_exec(*env, args, true);
				//check free
				exit(/* g_exit*/0);
			}
		}
		else
			run_exec(*env, args, false);
	}
	restore_fds(fd);
	//free
	return (1);
}

void	minishell_loop(char *input, t_env *env)
{
	char	**args;
	int		i;
	int		fd[2];

	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
	args = NULL;
	i = 0;
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
