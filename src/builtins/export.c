/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:17:57 by chsassi           #+#    #+#             */
/*   Updated: 2024/07/30 10:19:00 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*find_env_var(t_env *env_list, char *var)
{
	while (env_list)
	{
		if (!ft_strcmp(env_list->var, var))
			return (env_list);
		env_list = env_list->next;
	}
	return (NULL);
}

void	update_env_var(t_env *env_list, char *var_name, char *new_value)
{
	t_env	*var;

	var = find_env_var(env_list, var_name);
	if (var)
	{
		free(var->content);
		var->content = strdup(new_value);
	}
}

// t_env	*bin_export(t_all *pAll, t_env **env_list, char *var_name, char *value)
// {}
