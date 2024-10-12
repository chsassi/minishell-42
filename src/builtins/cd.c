/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:17:57 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 18:40:20 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_home(t_all *pAll)
{
	t_env	*home;

	home = find_env_var(*pAll->env, "HOME");
	if (!home || !home->content)
	{
		ft_putstr_fd("bash: cd: HOME not set\n", 2);
		return ;
	}
	if (chdir(home->content))
	{
		ft_putstr_fd("bash: cd: /home/user: No such file or directory\n", 2);
		return ;
	}
	update_env_var(pAll->env, "OLDPWD", get_env_var(*pAll->env, "PWD"));
	update_env_var(pAll->env, "PWD", home->content);
}

void	cd_previous_dir(t_all *pAll)
{
	t_env	*oldpwd;
	char	*new_dir;

	oldpwd = find_env_var(*pAll->env, "OLDPWD");
	new_dir = NULL;
	if (!oldpwd || !oldpwd->content)
	{
		ft_putstr_fd("bash: cd: OLDPWD not set\n", 2);
		pAll->status_code = 1;
		return ;
	}
	if (oldpwd->content && oldpwd->content[0])
		printf("%s\n", oldpwd->content);
	if (chdir(oldpwd->content))
	{
		ft_putstr_fd("bash: cd: /previous/directory:\
 No such file or directory\n", 2);
		return ;
	}
	update_env_var(pAll->env, "OLDPWD", get_env_var(*pAll->env, "PWD"));
	new_dir = getcwd(NULL, 0);
	if (new_dir)
	{
		update_env_var(pAll->env, "PWD", new_dir);
		free(new_dir);
	}
}

void	cd_upper_dir(t_all *pAll)
{
	char	*new_dir;

	new_dir = NULL;
	if (chdir(".."))
	{
		ft_putstr_fd("bash: cd: /previous/directory:\
 No such file or directory\n", 2);
		return ;
	}
	update_env_var(pAll->env, "OLDPWD", get_env_var(*pAll->env, "PWD"));
	new_dir = getcwd(NULL, 0);
	if (new_dir)
	{
		update_env_var(pAll->env, "PWD", new_dir);
		free(new_dir);
	}
}

void	cd_from_path(t_all *pAll, char *path)
{
	char	*new_dir;

	new_dir = NULL;
	if (chdir(path))
	{
		ft_putstr_fd("bash: cd: /absolute/path:\
 No such file or directory\n", 2);
		return ;
	}
	update_env_var(pAll->env, "OLDPWD", get_env_var(*pAll->env, "PWD"));
	new_dir = getcwd(NULL, 0);
	if (new_dir)
	{
		update_env_var(pAll->env, "PWD", new_dir);
		free(new_dir);
	}
}

void	bin_cd(t_all *pAll, t_shell *pShell)
{
	if (!pShell->cmd[1] || !ft_strcmp(pShell->cmd[1], "~"))
		cd_home(pAll);
	else if (!ft_strcmp(pShell->cmd[1], "-"))
		cd_previous_dir(pAll);
	else if (!ft_strcmp(pShell->cmd[1], ".."))
		cd_upper_dir(pAll);
	else
		cd_from_path(pAll, pShell->cmd[1]);
}
