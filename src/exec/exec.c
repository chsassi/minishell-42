/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:52:53 by chsassi           #+#    #+#             */
/*   Updated: 2024/08/19 16:42:13 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute(char *cmd, char **mtx, char **envp)
{

	int fd = open("./Makefile", O_RDONLY);
	int fd2 = open("./test_copy", O_WRONLY);
	printf("%d\n", fd);
	printf("%d\n", fd2);
	pid_t id = fork();

	if (id == 0)
	{

		dup2(fd, STDIN_FILENO);
		dup2(fd2, STDOUT_FILENO);
		printf("%d\n", fd2);

		execve(cmd, mtx, envp);
	}

	waitpid(-1, NULL, 0);
	close(fd);
	close(fd2);
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