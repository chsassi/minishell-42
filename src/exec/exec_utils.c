/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:40:15 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 18:40:20 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path_from_env(void)
{
	char	*env_path;
	char	**new_path;

	env_path = getenv("PATH");
	if (!env_path)
		return (NULL);
	new_path = ft_split(env_path, ':');
	return (new_path);
}

char	*find_executable_in_env(char **paths, char *command)
{
	char		*full_path;
	char		*tmp;

	if (ft_strchr(command, '/'))
	{
		if (!access(command, X_OK))
			return (ft_strdup(command));
		return (NULL);
	}
	while (paths && *paths)
	{
		tmp = ft_strjoin(*paths, "/");
		full_path = ft_strjoin(tmp, command);
		free(tmp);
		if (!access(full_path, X_OK))
			return (full_path);
		free(full_path);
		paths++;
	}
	return (NULL);
}
