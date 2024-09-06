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
	char	*s1;

	i = 0;
	s1 = ft_substr()
	while (ft_strcmp())
}

char	*new_expanded_string(char *input, t_env *envp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
