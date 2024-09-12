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

<<<<<<< HEAD
t_env	*find_env_var(t_env *env, char *var)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->var, var))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	swap_nodes(t_env *a, t_env *b)
{
	char	*tmp_var;
	tmp_var = a->var;
	char *tmp_content;
	tmp_content = a->content;

	a->var = b->var;
	a->content = b->content;
	a->is_hidden = b->is_hidden;
	b->var = tmp_var;
	b->content = tmp_content;
	b->is_hidden = a->is_hidden;
}

// t_env	*sort_list(t_env *node)
// {
=======
// t_env	*find_env_var(t_env *env, char *var)
//{
>>>>>>> 6b0ff0f31d450f29126e28793f5d49b9b77ea4b8
// 	t_env	*tmp;

// 	tmp = node;
// 	while (tmp && tmp->next)
// 	{
// 		if (tmp->var[0] < tmp->next->var[0])
// 			swap_nodes(tmp, tmp->next);
// 		printf("%s=%s\n", tmp->var, tmp->content);
// 		tmp = tmp->next;
// 	}
// 	return (tmp);
// }

<<<<<<< HEAD
t_env	*bin_export(char **args, t_env **env_list, char *var_name, char *value)
{
	t_env	*new_var;
	int		i;
	
	i = 1;
	// while per controllo degli argomenti
	// se strchr OK con '=' -> is hidden e' false e quindi var e' sia in export che in env
	// se is hidden e' true appare solo in export
	// se sommo la variabile con new value join tra old var e new value
}
=======
// t_env	*bin_export(t_all *pAll, t_env **env_list, char *var_name, char *value)
// {}
>>>>>>> 6b0ff0f31d450f29126e28793f5d49b9b77ea4b8
