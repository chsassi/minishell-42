/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:27:16 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 18:40:40 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_node_to_list(t_env **env_list, t_env *new_node)
{
	t_env	*current;

	current = NULL;
	if (!new_node)
		return ;
	current = *env_list;
	if (!current)
		*env_list = new_node;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

void	handle_env_var(t_env **env_list, t_env *existing_var, \
char *var_name, char *equal_sign)
{
	t_env	*new_node;

	new_node = NULL;
	if (existing_var)
	{
		if (equal_sign)
			update_env_var(env_list, var_name, equal_sign + 1);
		existing_var->is_hidden = false;
	}
	else
	{
		new_node = new_env_node(var_name);
		if (new_node)
		{
			set_var_content(new_node, equal_sign);
			add_node_to_list(env_list, new_node);
		}
	}
}

bool	export_var(t_all *pAll, char *arg)
{
	t_env	*existing_var;
	char	*equal_sign;
	char	*var_name;
	int		var_name_len;

	existing_var = NULL;
	equal_sign = ft_strchr(arg, '=');
	var_name = NULL;
	var_name_len = equal_sign - arg;
	if (equal_sign)
		var_name = ft_substr(arg, 0, var_name_len);
	else
		var_name = ft_strdup(arg);
	if (!is_valid_var("export", var_name))
	{
		pAll->status_code = 1;
		return (free(var_name), false);
	}
	existing_var = find_env_var(*pAll->env, var_name);
	handle_env_var(pAll->env, existing_var, var_name, equal_sign);
	return (free(var_name), true);
}

void	print_export(t_env *var)
{
	printf("declare -x %s", var->var);
	if (var->content)
		printf("=\"%s\"", var->content);
	printf("\n");
}
