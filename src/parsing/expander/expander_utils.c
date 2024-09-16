/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:53:05 by brulutaj          #+#    #+#             */
/*   Updated: 2024/09/16 15:03:52 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*find_env_string(char *input, t_env *envp, int len)
{
	t_env	*tmp;
	char *substring;
	
	tmp = envp;
	while (tmp)
	{
		substring = ft_substr(input, 0, len);
		if (!ft_strncmp(substring, tmp->var, ft_strlen(substring) + 1))
		{
			free(substring);
			return (ft_strdup(tmp->content));
		}
		free(substring);
		tmp = tmp->next;
	}
	return (ft_strdup(""));
}

char	*env_string(char *input, int *i, t_env *envp)
{
	int	j;
	int	len;

	j = (*i);
	len = 0;
    (*i)++;
    if (input[*i] != '\0')
    {
		if (input[*i] == '?')
		{
			(*i)++;
			return (ft_itoa(123));
		}
		else if (input[*i] == '_' || ft_isalpha(input[*i]))
		{
			(*i)++;
			while (input[*i] == '_' || ft_isalnum(input[*i]))
			    (*i)++;
			len = ((*i) - j) - 1;
			return (find_env_string(input + (j + 1), envp, len));
		}
    }
	return (ft_strdup("$"));
}
