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

void	handle_heredoc(char *delim)
{
	char	*line;
	int		len;
	int		i;

	line = NULL;
	len = 0;
	i = 0;
	while (1)
	{
		i++;
		write(1, "> ", 2);
		line = gnl(STDIN_FILENO);
		if (!line)
		{
			printf("bash: warning: here-document at line %i \
delimited by end-of-file (wanted `%s')\n", i, delim);
			break ;
		}
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (!ft_strcmp(line, delim))
			break ;
	}
	free(line);
	g_exit = 0;
}