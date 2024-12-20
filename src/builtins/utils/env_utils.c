/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:35:39 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 18:40:40 by chsassi          ###   ########.fr       */
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

bool	update_env_var(t_env **env_list, char *var_name, char *new_value)
{
	t_env	*var;

	var = find_env_var(*env_list, var_name);
	if (var)
	{
		free(var->content);
		var->content = ft_strdup(new_value);
	}
	else
	{
		var = ft_calloc(1, sizeof(t_env));
		if (!var)
			return (false);
		var->var = ft_strdup(var_name);
		if (!var->var)
			return (free(var), false);
		var->content = ft_strdup(new_value);
		if (!var->content)
			return (free(var->var), free(var), false);
		env_add_back(env_list, var);
	}
	return (true);
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

void	print_env(t_env *var)
{
	if (!var->is_hidden)
	{
		printf("%s=", var->var);
		if (var->content)
			printf("%s", var->content);
		printf("\n");
	}
}
