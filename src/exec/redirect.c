/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:55:15 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/01 11:55:16 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	restore_fds(int fd[2])
{
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
}

void	handle_redirection(char *type, char *file, int fd[2])
{
	int	redirect_fd;

	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
	if (!ft_strcmp(type, REDIRECT_IN))
		redirect_fd = open(file, O_RDONLY);
	else if (!ft_strcmp(type, REDIRECT_OUT))
		redirect_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (!ft_strcmp(type, REDIRECT_APPEND))
		redirect_fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		return ;
	if (redirect_fd < 0)
	{
		printf("Invalid file descriptor");
		return ;
	}
	if (!ft_strcmp(type, REDIRECT_IN))
		dup2(redirect_fd, STDIN_FILENO);
	else
		dup2(redirect_fd, STDOUT_FILENO);
	close(redirect_fd);
}
