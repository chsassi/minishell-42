/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:52:46 by brulutaj          #+#    #+#             */
/*   Updated: 2024/09/04 17:38:18 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*env_string(char *input, t_env *envp, int len)
{
	int		i;

	i = 0;
	while (envp->next != NULL)
	{
		if (!ft_strncmp(input, envp->var, len))
			return (envp->content);
		envp = envp->next;
	}
	return (ft_strdup(""));
}

char	*new_expanded_string(char *input, t_env *envp)
{
	int		i;
	int		j;
	char	*env_str

	i = 0;
	j = 0;
	env_str = NULL;
	while (input && input[i])
	{
		if (input[i] == '$')
		{
			j = i;
			env_string(input + i, envp, env_token_length(input + i));

		}

				
	}
}

char	*expansion(char *input, t_env *envp)
{
	int		n;
	char	*input_exp;
	int		i;

	i = 0;
	n = 0;
	input_exp = ft_strdup(input);
	while (input_exp && input_exp[i] != '\0')
	{
		if (input_exp[i] == '$')
			count_env_token(input_exp, i, n);
		i++;
	}
	i = 0;
	while (i < n)
	{
		input_exp = new_expanded_string(input_exp, envp);
		i++;
	}
	return (input_exp);
}
