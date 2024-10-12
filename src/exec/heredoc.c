/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:51:07 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 18:40:20 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * return `true` if everything is okay, `false` when ctrl + c was pressed
 */
bool	heredoc_loop(char *delim, int fd)
{
	char	*line;
	int		i;

	i = 0;
	// add signal
	while (1)
	{
		i++;
		line = readline("> ");
		// update status code from last signal
		// check for status code == 130 -> stop all heredocs
		// return (false);
		if (!line)
		{
			printf("bash: warning: here-document at line %i \
delimited by end-of-file (wanted `%s')\n", i, delim);
			break ;
		}
		if (!ft_strcmp(line, delim))
			break ;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	free(line);
	return (true);
}

void	handle_heredoc(t_all *pAll, char *delim, char *filename)
{
	int		fd;

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("Error opening heredoc", 2);
		free_all(pAll, true, 1);
		return ;
	}
	heredoc_loop(delim, fd);
	pAll->status_code = 0;
}

bool	is_last_heredoc(t_shell *shell, int red_idx)
{
	int	i;
	int	last;

	i = -1;
	last = -1;
	while (shell->redirects && shell->redirects[++i])
	{
		if (!ft_strcmp(shell->redirects[i], HEREDOC)
			|| !ft_strcmp(shell->redirects[i], REDIRECT_IN))
			last = i;
	}
	return (red_idx == last);
}

bool	parse_shell_heredoc(t_all *pAll, t_shell *curr, int red_idx)
{
	char	*n;
	char	*name;

	name = NULL;
	if (!ft_strcmp(curr->redirects[red_idx], HEREDOC))
	{
		n = ft_itoa(curr->cmd_idx);
		name = ft_strjoin(".heredoc", n);
		if (!n || !name)
			return (free(n), free(name), free_all(pAll, true, 1), false);
		free(n);
		handle_heredoc(pAll, curr->redirects[red_idx + 1], name);
		if (is_last_heredoc(curr, red_idx))
			curr->last_heredoc = name;
		else
		{
			unlink(name);
			free(name);
		}
	}
	return (true);
}

void	exec_heredocs(t_all *pAll)
{
	t_shell	*curr;
	int		i;
	int		shell_idx;

	curr = pAll->shell;
	shell_idx = 0;
	while (curr)
	{
		i = -1;
		while (curr->redirects && curr->redirects[++i])
			parse_shell_heredoc(pAll, curr, i);
		shell_idx++;
		curr = curr->next;
	}
}
