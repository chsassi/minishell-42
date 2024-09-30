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

void	bin_export(t_env **env_list, char **args)
{
	t_env	*current;
	int		i;

	if (!args[1])
	{
		current = *env_list;
		while (current)
		{
			print_export(current);
			current = current->next;
		}
		return ;
	}
	i = 1;
	while (args[i])
	{
		export_var(env_list, args[i]);
		i++;
	}
}
