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

<<<<<<< HEAD
void	bin_cd(t_env *env_list, const char *path)
{
	t_env	*pwd;
	t_env	*oldpwd;
	
	pwd = find_env_var(env_list, "PWD");
	oldpwd = find_env_var(env_list, "OLDPWD");
	if (!ft_strcmp(path, "-"))
	{
		if (!oldpwd || !oldpwd->content)
		{
			printf("bash: cd: OLDPWD not set\n");
			return ;
		}
		// stampa
		path = oldpwd->content;
	}
	if (!ft_strcmp(path, ".."))
	{
		if (!oldpwd || !oldpwd->content)
		{
			printf("bash: cd: ..: Permission denied");
			return ;
		}
		path = oldpwd->content;
	}
}

void builtin_cd(t_env *env_list, const char *path)
{
	t_env *pwd_var = find_env_var(env_list, "PWD");
	t_env *oldpwd_var = find_env_var(env_list, "OLDPWD");

	if (chdir(path) != 0)
	{
		perror("cd");
		return ;
	}
	if (pwd_var)
	{
		if (oldpwd_var)
		{
			free(oldpwd_var->content);
			oldpwd_var->content = ft_strdup(pwd_var->content);
		}
		else
		{
			t_env *new_oldpwd;
			new_oldpwd = (t_env *)malloc(sizeof(t_env));
			new_oldpwd->var = ft_strdup("OLDPWD");
			new_oldpwd->content = ft_strdup(pwd_var->content);
			new_oldpwd->is_hidden = false;
			new_oldpwd->next = env_list;
			env_list = new_oldpwd;
		}
	}
	char	*new_pwd;
	new_pwd = getcwd(NULL, 0);
	if (new_pwd)
	{
		update_env_var(env_list, "PWD", new_pwd);
		free(new_pwd);
	}
	else
		perror("cd: getcwd");
}

=======
void	cd_home(t_env *env_list)
{
	t_env	*home;
>>>>>>> fbb75f5b0f4482de4c8334639747f254120473b0

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
