/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:50 by mgalmari          #+#    #+#             */
/*   Updated: 2024/06/18 14:34:59 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_expansion(t_list *envp, char *name_env)
{
	int		start;
	char	*env;
	int		len_env;

	if (!name_env)
		return (NULL);
	start = ft_strlen(name_env) + 1;
	len_env = find_len_env(envp, name_env);
	env = ft_calloc(len_env + 1, sizeof(char));
	if (!env)
		return (NULL);
	env = find_expansion_env(envp, name_env);
	return (env);
}

char	*get_name_env(char *str)
{
	int		i;
	int		index_dollar_sign;
	int		len_env;
	char	*name_env;

	i = 0;
	index_dollar_sign = get_index_special_char(str, '$') + 1;
	if (index_dollar_sign == -1)
		return (NULL);
	len_env = get_len_word(str, index_dollar_sign);
	name_env = ft_calloc(len_env + 1, sizeof(char));
	if (!name_env)
		return (NULL);
	while ((str && str[index_dollar_sign]) && i < len_env)
	{
		name_env[i] = str[index_dollar_sign];
		index_dollar_sign++;
		i++;
	}
	return (name_env);
}

char	*get_env(char *str, t_all all_info)
{
	char	*env;
	char	*name_env;

	name_env = get_name_env(str);
	if (!name_env)
		return (NULL);
	env = get_expansion(all_info.envp, name_env);
	if (!env)
		return (NULL);
	free(name_env);
	return (env);
}

//usare semplicemente strchr? o meno efficace?
