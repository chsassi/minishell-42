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

void	bin_cd(t_env *env_list, char *path)
{
	if (!path || !ft_strcmp(path, "~"))
		cd_home(env_list);
	else if (!ft_strcmp(path, "-"))
		cd_oldpwd(env_list);
	else if (!ft_strcmp(path, ".."))
		cd_up(env_list);
	else
	{
		if (chdir(path))
		{
			perror("bash: cd");
			return ;
		}
		update_env_var(env_list, "OLDPWD", get_env_var(env_list, "PWD"));
		char	*new_dir;
		new_dir = getcwd(NULL, 0);
		if (new_dir)
		{
			update_env_var(env_list, "PWD", new_dir);
			free(new_dir);
		}
		else
			perror("bash: cd");
	}
}

// da controllare gli argomenti post cd nella lista t_env
// se il new path e' valido, aggiornare PATH nella lista t_env

// .. -> directory dove ci si trovava in precedenza
// -  -> directory precedente alla corrente
// no argomento, ~ -> home