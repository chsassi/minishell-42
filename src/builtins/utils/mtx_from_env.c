/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_from_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:06:27 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/01 16:06:29 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_env_vars(t_env *env_list)
{
	int	count;

	count = 0;
	while (env_list)
	{
		if (!env_list->is_hidden)
			count++;
		env_list = env_list->next;
	}
	return (count);
}

void	strjoin_loop(t_env *current, char **env_mtx, char *tmp)
{
	int	i;

	i = 0;
	while (current)
	{
		if (!current->is_hidden)
		{
			tmp = ft_strjoin(current->var, "=");
			if (!tmp)
			{
				free_mtx(env_mtx);
				return ;
			}
			env_mtx[i] = ft_strjoin_gnl(tmp, current->content);
			if (!env_mtx[i])
			{
				free_mtx(env_mtx);
				return ;
			}
			i++;
		}
		current = current->next;
	}
	env_mtx[i] = NULL;
}

char	**create_env_mtx(t_env *env_list)
{
	int		count;
	int		i;
	char	*tmp;
	char	**env_mtx;
	t_env	*current;

	count = count_env_vars(env_list);
	i = 0;
	tmp = NULL;
	env_mtx = (char **)malloc(sizeof(char *) * (count + 1));
	if (!env_mtx)
		return (NULL);
	current = env_list;
	strjoin_loop(current, env_mtx, tmp);
	return (env_mtx);
}
