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

char	**get_path_from_env(void/* t_all *pAll */)
{
	char	*env_path;
	char	**new_path;

	env_path = getenv("PATH");
	if (!env_path)
		return NULL;
	new_path = ft_split(env_path, ':');
	return (new_path);	
}

//da cambiare command con ptr a struct;
char	*find_executable_in_env(char **paths, char *command)
{
	char		*str_tojoin;
	const int	len = ft_strlen(command);

	if (ft_strchr(command, '/'))
	{
		if (!access(command, X_OK))
			return (ft_strdup(command));
		return (NULL);
	}
	while (paths && *paths)
	{
		if (len > 0 && command[len - 1] == '/')
			str_tojoin = ft_strjoin(*paths, command);
		else
		{
			str_tojoin = ft_strjoin(*paths, "/");
			str_tojoin = ft_strjoin_gnl(str_tojoin, command);
		}
		if (!access(str_tojoin, X_OK))
			return (str_tojoin);
		paths++;
	}
	return (free(str_tojoin), NULL);
}

void	fork_cmd_process(char *cmd, char **mtx, char **envp)
{
	//cerca path del comando; -se il comando non esiste, msg errore e g_exit = 127;
	pid_t id = fork();
	if (id == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(cmd, mtx, envp);
		exit(0);
	}
	free(/*path*/NULL);
}

void	run_builtin(char	**args, t_env **env_list) //da cambiare: accettera' la struct concordata
{
/* 	if (!ft_strcmp(args[0], "echo"))
		bin_echo(args);
	else  */if (!ft_strcmp(args[0], "cd"))
		bin_cd(*env_list, args[1]);
	else if (!ft_strcmp(args[0], "pwd"))
		bin_pwd();
	else if (!ft_strcmp(args[0], "export"))
		bin_export(env_list, args);
	else if (!ft_strcmp(args[0], "unset"))
		bin_unset(env_list, args[1]);
	else if (!ft_strcmp(args[0], "env"))
		bin_env(*env_list);
	else if (!ft_strcmp(args[0], HEREDOC))
		handle_heredoc(args[1]);
	// else if (!ft_strcmp(args[0], "exit"))
	// 	return (bin_exit();
	else
		return ;
}

int	run_exec(t_all *pAll);
/*{

} */
