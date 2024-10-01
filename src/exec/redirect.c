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

void	handle_redirection(char *type, char *file)
{
	int	fd;

	if (!ft_strcmp(type, REDIRECT_IN))
		fd = open(file, O_RDONLY);
	else if (!ft_strcmp(type, REDIRECT_OUT))
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (!ft_strcmp(type, REDIRECT_APPEND))
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		return ;
	if (fd < 0)
	{
		//printa errore
		//free
		return ;
	}
	if (!ft_strcmp(type, REDIRECT_IN))
		dup2(fd, STDIN_FILENO);
	else
		dup2(fd, STDOUT_FILENO);
	close(fd);
}
