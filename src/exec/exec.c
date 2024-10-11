/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:05:35 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/11 15:38:11 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fork_cmd(t_all *pAll, char *cmd, char **args, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(cmd, args, envp);
		free_all(pAll, true, 127);
	}
	else if (pid < 0)
	{
		ft_putstr_fd("bash: fork: retry: Resource temporarily unavailable", 2);
		free_all(pAll, true, 1);
	}
}

int	run_builtin(t_all *pAll, t_shell *pShell)
{
	if (!ft_strcmp(pShell->cmd[0], "echo"))
		return (bin_echo(pAll, pShell), 1);
	else if (!ft_strcmp(pShell->cmd[0], "cd"))
		return (bin_cd(pAll, pShell), 1);
	else if (!ft_strcmp(pShell->cmd[0], "pwd"))
		return (bin_pwd(pAll), 1);
	else if (!ft_strcmp(pShell->cmd[0], "export"))
		return (bin_export(pAll, pShell), 1);
	else if (!ft_strcmp(pShell->cmd[0], "unset"))
		return (bin_unset(pAll, pShell), 1);
	else if (!ft_strcmp(pShell->cmd[0], "env"))
		return (bin_env(pAll), 1);
	else if (!ft_strcmp(pShell->cmd[0], "exit"))
		return (bin_exit(pAll, pShell), 1);
	else
		return (0);
}

char	*access_exec(t_all *pAll, t_shell *pShell, bool inside_fork)
{
	char	**paths;
	char	*cmd_path;

	paths = get_path_from_env();
	cmd_path = find_executable_in_env(paths, pShell->cmd[0]);
	if (!cmd_path)
	{
		printf("%s: command not found\n", pShell->cmd[0]);
		pAll->status_code = 127;
		free_mtx(paths);
		if (inside_fork)
			exit(pAll->status_code);
		return (NULL);
	}
	return (cmd_path);
}

bool	run_exec(t_all *pAll, t_shell *pShell, bool inside_fork)
{
	char	*cmd_path;
	char	**env_mtx;

	if (!pShell->cmd || !pShell->cmd[0])
		return (false);
	if (run_builtin(pAll, pShell))
	{
		if (inside_fork)
			exit(pAll->status_code);
		return (true);
	}
	cmd_path = access_exec(pAll, pShell, inside_fork);
	if (!cmd_path)
		return (false);
	// free(pShell->cmd[0]);
	// pShell->cmd[0] = cmd_path;
	env_mtx = create_env_mtx(*pAll->env);
	if (!inside_fork)
		fork_cmd(pAll, cmd_path, pShell->cmd, env_mtx);
	else
		exec_cmd(pAll, cmd_path, pShell->cmd, env_mtx);
	return (free(cmd_path), free_mtx(env_mtx), true);
}
