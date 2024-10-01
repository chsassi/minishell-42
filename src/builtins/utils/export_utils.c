/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:27:16 by chsassi           #+#    #+#             */
/*   Updated: 2024/09/30 15:27:18 by chsassi          ###   ########.fr       */
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
			update_env_var(*env_list, var_name, equal_sign + 1);
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

void	export_var(t_env **env_list, char *arg)
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
	existing_var = find_env_var(*env_list, var_name);
	handle_env_var(env_list, existing_var, var_name, equal_sign);
	free(var_name);
}

void	print_export(t_env *var)
{
	printf("declare -x %s", var->var);
	if (var->content)
		printf("=\"%s\"", var->content);
	printf("\n");
}
