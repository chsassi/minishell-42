/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:05:35 by chsassi           #+#    #+#             */
/*   Updated: 2024/09/25 11:51:11 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fork_cmd(char *cmd, char **args, char **envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
	status = 0;
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (execve(cmd, args, envp) == -1)
			exit(g_exit = 127);
		exit(0);
	}
	else if (pid < 0)
		ft_putstr_fd("bash: fork: retry: Resource temporarily unavailable", 2);
}

int	run_builtin(char **args, t_env **env_list) //da cambiare: accettera' la struct concordata
{
/* 	if (!ft_strcmp(args[0], "echo"))
		return (bin_echo(args), 1);
	else  */if (!ft_strcmp(args[0], "cd"))
		return (bin_cd(*env_list, args[1]), 1);
	else if (!ft_strcmp(args[0], "pwd"))
		return (bin_pwd(), 1);
	else if (!ft_strcmp(args[0], "export"))
		return (bin_export(env_list, args), 1);
	else if (!ft_strcmp(args[0], "unset"))
		return (bin_unset(env_list, args[1]), 1);
	else if (!ft_strcmp(args[0], "env"))
		return (bin_env(*env_list), 1);
	else if (!ft_strcmp(args[0], HEREDOC))
		return (handle_heredoc(args[1]), 1);
	// else if (!ft_strcmp(args[0], "exit"))
	// 	return (bin_exit(), 1);
	else
		return (0);
}

void	run_exec(t_env *env, char **args, bool inside_fork)
{
	char	*cmd_path;
	char	**paths;
	char	**env_mtx;

	if (!args || !args[0])
		return ;
	if (run_builtin(args, &env))
	{
		if (inside_fork)
			exit(/*g_exit*/0);
		return ;
	}
	paths = get_path_from_env();
	cmd_path = find_executable_in_env(paths, args[0]);
	if (!cmd_path)
	{
		printf("%s: command not found\n", args[0]);
		g_exit = 127;
		free_mtx(paths);
		return ;
	}
	env_mtx = create_env_mtx(env);
	if (!inside_fork)
		exec_cmd(cmd_path, args, env_mtx);
	else
		fork_cmd(cmd_path, args, env_mtx);
	free(cmd_path);
	free_mtx(env_mtx);
	free_mtx(paths);
}
