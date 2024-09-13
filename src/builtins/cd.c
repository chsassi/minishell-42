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


// da controllare gli argomenti post cd nella lista t_env
// se il new path e' valido, aggiornare PATH nella lista t_env

// .. -> directory dove ci si trovava in precedenza
// -  -> directory precedente alla corrente
// no argomento, ~ -> home