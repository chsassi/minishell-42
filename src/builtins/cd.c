/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:17:57 by chsassi           #+#    #+#             */
/*   Updated: 2024/07/30 10:19:00 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_home(t_env *env_list)
{
	t_env	*home;

	home = find_env_var(env_list, "HOME");
	if (!home || !home->content)
	{
		ft_putstr_fd("bash: cd:	HOME not set\n", 2);
		return ;
	}
	if (chdir(home->content))
	{
		ft_putstr_fd("bash: cd: /home/user: No such file or directory", 2);
		return ;
	}
	update_env_var(env_list, "OLDPWD", get_env_var(env_list, "PWD"));
	update_env_var(env_list, "PWD", home->content);
}

void	cd_previous_dir(t_env *env_list)
{
	t_env	*oldpwd;
	char	*new_dir;

	oldpwd = find_env_var(env_list, "OLDPWD");
	new_dir = NULL;
	if (!oldpwd || !oldpwd->content)
	{
		ft_putstr_fd("bash: cd: OLDPWD not set\n", 2);
		return ;
	}
	printf("%s\n", oldpwd->content);
	if (chdir(oldpwd->content))
	{
		ft_putstr_fd("bash: cd: /previous/directory: \
No such file or directory", 2);
		return ;
	}
	update_env_var(env_list, "OLDPWD", get_env_var(env_list, "PWD"));
	new_dir = getcwd(NULL, 0);
	if (new_dir)
	{
		update_env_var(env_list, "PWD", new_dir);
		free(new_dir);
	}
}

void	cd_upper_dir(t_env *env_list)
{
	char	*new_dir;

	new_dir = NULL;
	if (chdir(".."))
	{
		perror("bash: cd: /previous/directory: No such file or directory");
		return ;
	}
	update_env_var(env_list, "OLDPWD", get_env_var(env_list, "PWD"));
	new_dir = getcwd(NULL, 0);
	if (new_dir)
	{
		update_env_var(env_list, "PWD", new_dir);
		free(new_dir);
	}
}

void	bin_cd(t_env *env_list, char *path)
{
	char	*new_dir;

	new_dir = NULL;
	if (!path || !ft_strcmp(path, "~"))
		cd_home(env_list);
	else if (!ft_strcmp(path, "-"))
		cd_previous_dir(env_list);
	else if (!ft_strcmp(path, ".."))
		cd_upper_dir(env_list);
	else
	{
		if (chdir(path))
		{
			ft_putstr_fd("bash: cd: /absolute/path: \
No such file or directory\n", 2);
			return ;
		}
		update_env_var(env_list, "OLDPWD", get_env_var(env_list, "PWD"));
		new_dir = getcwd(NULL, 0);
		if (new_dir)
		{
			update_env_var(env_list, "PWD", new_dir);
			free(new_dir);
		}
	}
}

