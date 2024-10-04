/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:51:07 by chsassi           #+#    #+#             */
/*   Updated: 2024/09/25 11:51:18 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_loop(char *delim, char *line, int fd)
{
	int	i;

	i = 0;
	while (1)
	{
		i++;
		line = readline("> ");
		if (!line || !ft_strcmp(line, delim))
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		if (!line)
		{
			printf("bash: warning: here-document at line %i \
delimited by end-of-file (wanted `%s')\n", i, delim);
			break ;
		}
		if (!ft_strcmp(line, delim))
			break ;
	}
}

void	handle_heredoc(char *delim, char *filename)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("Error opening heredoc", 2);
		return ;
	}
	heredoc_loop(delim, line, fd);
	free(line);
	g_exit = 0;
}

void	exec_heredocs(t_shell *cmds)
{
	t_shell	*curr;
	char	*name;
	char	*n;
	int		i;

	curr = cmds;
	name = NULL;
	while (curr)
	{
		i = -1;
		while (curr->redirects && curr->redirects[++i])
		{
			if (ft_strcmp(curr->redirects[i], HEREDOC))
			{
				n = ft_itoa(i);
				free(curr->last_heredoc);
				curr->last_heredoc = ft_strjoin(".heredoc", n);
				free(n);
				// malloc failure check
				handle_heredoc(curr->redirects[i + 1], name);
				// check if it's the last input redirect
				// unlink(name);
			}
		}
		curr = curr->next;
	}
}
