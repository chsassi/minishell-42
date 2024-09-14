/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:17:57 by chsassi           #+#    #+#             */
/*   Updated: 2024/09/13 18:31:26 by brulutaj         ###   ########.fr       */
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
		var->content = ft_strdup(new_value);
	}
}

char	*get_env_var(t_env *env_list, char *var_name)
{
	while (env_list)
	{
		if (!ft_strcmp(env_list->var, var_name))
			return (env_list->content);
		env_list = env_list->next;
	}
	return (NULL);
}

t_env	*bin_env(t_env *env)
{
	t_env	*current;
	current = env;

	while (current)
	{
		if (!current->is_hidden)
			printf("%s=%s\n", current->var, current->content);
		current = current->next;
	}
	return (env);
}
