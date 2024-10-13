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
	if (ft_strlen(command) == 0)
		return (NULL);
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
