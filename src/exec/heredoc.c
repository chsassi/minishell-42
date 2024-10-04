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

void	run_all_heredocs(t_shell *cmds)
{
	t_shell	*curr;
	char	*name;
	char	*n;
	int		i;

	curr = cmds;
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

void	handle_heredoc(char *delim, char *filename)
{
	char	*line;
	// int		len;
	int		i;
	int		fd;

	line = NULL;
	// len = 0;
	i = 0;
	// change CTRL+C
	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY);
	// fd == -1
	while (1)
	{
		i++;
		// write(1, "> ", 2);
		line = readline("> ");
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		// WRITE `line` in `.heredoc-<block idx>`
		// IF CTRL+C => break all HEREDOCS;
		if (!line)
		{
			printf("bash: warning: here-document at line %i \
delimited by end-of-file (wanted `%s')\n", i, delim);
			break ;
		}
		// len = ft_strlen(line);
		// if (line[len - 1] == '\n')
		// 	line[len - 1] = '\0';
		if (!ft_strcmp(line, delim))
			break ;
	}
	free(line);
	g_exit = 0;
}
