/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:05:35 by chsassi           #+#    #+#             */
/*   Updated: 2024/08/31 17:05:42 by chsassi          ###   ########.fr       */
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

/* void	execute_command(t_all *pAll)
{
	char	**paths;
	char	*cmd_path;

	if (run_exec(pAll))
		return ;
	paths = get_path_from_env();
	cmd_path = find_executable_in_env(paths, pAll->node->content);
	if (!cmd_path)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(pAll->node->content, 2);
		g_exit = 127;
	}
	exec_cmd(cmd_path, pAll->node->args, pAll->envp);
	free(cmd_path);
	ft_free_matrix(paths);
} */

int	run_exec(t_all *pAll);
/* {   
	if (!ft_strcmp(pAll->node->content, "echo"))
		return (bin_echo(pAll));
	else if (!ft_strcmp(pAll->node->content, "cd"))
		return (bin_cd());
	else if (!ft_strcmp(pAll->node->content, "pwd"))
		return (bin_pwd());
	else if (!ft_strcmp(pAll->node->content, "export"))
		return (bin_export();
	else if (!ft_strcmp(pAll->node->content, "unset"))
		return (bin_unset());
	else if (!ft_strcmp(pAll, "env"))
		return (bin_env(pAll));
	else if (!ft_strcmp(pAll->node->content, "exit"))
		return (bin_exit());
	else
		return (0); 
} */
