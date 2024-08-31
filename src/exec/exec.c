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

char	**get_path_from_env(t_all *pAll)
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
			str_tojoin = ft_strjoin(paths, command);
		else
		{
			str_tojoin = ft_strjoin(paths, "/");
			str_tojoin = ft_strjoin_gnl(str_tojoin, command);
		}
		if (!access(str_tojoin, X_OK))
			return (str_tojoin);
		paths++;
	}
	return (free(str_tojoin), NULL);
}

void	exec_cmd(char *cmd, char **mtx, char **envp)
{
	//cerca path del comando; -se il comando non esiste, msg errore e exit g_status_code = 127;
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


int	run_exec(t_all *pAll);
/*{     if (!ft_strcmp(pAll->node->content, "echo"))
		return (run_echo(pAll));
	else if (!ft_strcmp(pAll->node->content, "cd"))
		return (run_cd());
	else if (!ft_strcmp(pAll->node->content, "pwd"))
		return (run_pwd());
	else if (!ft_strcmp(pAll->node->content, "export"))
		return (run_export();
	else if (!ft_strcmp(pAll->node->content, "unset"))
		return (run_unset());
	else if (!ft_strcmp(pAll, "env"))
		return (run_env(pAll));
	else if (!ft_strcmp(pAll->node->content, "exit"))
		return (run_exit());
	else
		return (0); 
}*/
