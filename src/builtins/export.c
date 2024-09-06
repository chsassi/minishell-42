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

// t_env	*find_env_var(t_env *env, char *var)
// {
// 	t_env	*tmp;

// 	tmp = env;
// 	while (tmp)
// 	{
// 		if (!ft_strcmp(tmp->var, var))
// 			return (tmp);
// 		tmp = tmp->next;
// 	}
// 	return (NULL);
// }

// t_env	*bin_export(t_all *pAll, t_env **env_list, char *var_name, char *value)
// {
// 	t_env *new_var;

// 	new_var = find_env_var(*env_list, var_name);
// 	if (!pAll->prompt[1])
// 	{

// 	}
// 	if (new_var)
// 	{
// 		if (value)
// 		{
// 			free(new_var->content);
// 			new_var->content = strdup(value);
// 		}
// 		new_var->is_hidden = false;
// 	}
// 	else
// }