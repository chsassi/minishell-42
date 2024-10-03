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

void	check_redirection(char **args, int fd[2])
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!ft_strcmp(args[i], REDIRECT_IN)
			|| !ft_strcmp(args[i], REDIRECT_OUT)
			|| !ft_strcmp(args[i], REDIRECT_APPEND))
		{
			handle_redirection(args[i], args[i + 1], fd);
			args[i] = NULL;
			break ;
		}
		i++;
	}
}

int	process_input(char *input, t_env **env, int fd[2])
{
	char	**args;

	args = ft_split(input, ' ');
	if (!args || !args[0])
	{
		free_mtx(args);
		return (0);
	}
	check_redirection(args, fd);
	if (run_builtin(args, env))
	{
		restore_fds(fd);
		free_mtx(args);
		return (1);
	}
	run_exec(*env, args);
	restore_fds(fd);
	free_mtx(args);
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
			continue ;
		if (ft_strlen(input) > 0)
			add_history(input);
		free(input);
	}
}
