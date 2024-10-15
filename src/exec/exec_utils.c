/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:40:15 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/13 14:58:54 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path_from_env(t_all *pAll)
{
	t_env	*ptr;
	char	**new_path;

	ptr = find_env_var(*pAll->env, "PATH");
	if (!ptr)
		return (NULL);
	new_path = ft_split(ptr->content, ':');
	return (new_path);
}

static char	*check_relative_path(char *command)
{
	int			fd;

	if (ft_strchr(command, '/'))
	{
		fd = open(command, O_DIRECTORY);
		if (fd != -1)
			return (close(fd), NULL);
		if (!access(command, X_OK))
			return (ft_strdup(command));
		return (NULL);
	}
	return (command);
}

char	*find_executable_in_env(char **paths, char *command)
{
	int			fd;
	char		*full_path;
	char		*tmp;

	if (ft_strlen(command) == 0 || !check_relative_path(command))
		return (NULL);
	while (paths && *paths)
	{
		tmp = ft_strjoin(*paths, "/");
		full_path = ft_strjoin(tmp, command);
		free(tmp);
		fd = open(full_path, O_DIRECTORY);
		if (!access(full_path, X_OK) && !access(full_path, F_OK) && fd == -1)
			return (full_path);
		close(fd);
		free(full_path);
		paths++;
	}
	return (NULL);
}
