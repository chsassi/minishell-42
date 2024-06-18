/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:50 by mgalmari          #+#    #+#             */
/*   Updated: 2024/06/18 14:34:59 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_len_env(t_list *envp, char *name_env)
{
	t_list	*tmp;
	char	*content;
	int		len;
	int		lst_size;

	tmp = envp;
	content = NULL;
	len = ft_strlen(name_env);
	lst_size = ft_lstsize(envp);
	while (tmp && lst_size > 0)
	{
		content = (char *)tmp->content;
		if (lst_size > 0 && !ft_strncmp(content, name_env, len))
			return (ft_strlen(content) - (len + 1));
		tmp = tmp->next;
		lst_size--;
	}
	return (-1);
}

char	*find_expansion_env(t_list *envp, char *name_env)
{
	t_list	*tmp;
	char	*content;
	int		len;

	tmp = envp;
	content = NULL;
	len = ft_strlen(name_env) + 1;
	while (tmp)
	{
		content = (char *)tmp->content;
		if (!ft_strncmp(content, name_env, len - 1))
			return (&content[len]);
		tmp = tmp->next;
	}
	return (ft_strdup(""));
}
