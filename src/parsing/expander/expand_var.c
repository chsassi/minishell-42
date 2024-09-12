/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:52:46 by brulutaj          #+#    #+#             */
/*   Updated: 2024/09/12 18:00:09 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*new_exp_string(char *input_exp, t_env *envp, int *i)
{
	char	*exp_str;

	exp_str = NULL;
	exp_str = env_string(input_exp, i);
	
}

char	*expansion(char *input, t_env *envp)
{
	char	*input_exp;
	char	*env_var;
	int		i;

	(void)envp;
	i = 0;
	input_exp = ft_strdup(input);
	env_var = NULL;
	while (input_exp && input_exp[i] != '\0')
	{
		if (input[i] == '\'')
			i += quote_token_length(input + i);
		if (input_exp[i] == '$')
		{
			env = 
			input_exp = new_exp_string(input_exp, envp, &i);
		}
		i++;
	}
	return (input_exp);
}
