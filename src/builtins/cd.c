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

// da controllare gli argomenti post cd nella lista t_env
// se il new path e' valido, aggiornare PATH nella lista t_env

// .. -> directory dove ci si trovava in precedenza
// -  -> directory precedente alla corrente
// no argomento, ~ -> home