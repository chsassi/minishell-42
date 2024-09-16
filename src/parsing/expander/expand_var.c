/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:52:46 by brulutaj          #+#    #+#             */
/*   Updated: 2024/09/16 09:40:20 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*new_exp_string(char *input_exp, t_env *envp, int *i)
{
	char	*first_str;
	char	*second_str;
	char	*third_str;
	char	*result;

	first_str = NULL;
	second_str = NULL;
	third_str = NULL;
	result = NULL;
	if ((*i) != 0)
		first_str = ft_substr(input_exp, 0, (*i));
	else
		first_str = ft_strdup("");
	second_str = env_string(input_exp, i, envp);
	third_str = ft_strdup(input_exp + (*i));
	result = ft_strjoin_gnl(first_str, second_str);
	free(second_str);
	result= ft_strjoin_gnl(result, third_str);
	free(third_str);
	return(result);
}

char	*expansion(char *input, t_env *envp)
{
	char	*input_exp;
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	input_exp = ft_strdup(input);
	while (input_exp && input_exp[i] != '\0')
	{
		if (input[i] == '\'')
			i += quote_token_length(input + i);
		if (input_exp[i] == '$')
		{
			tmp = new_exp_string(input_exp, envp, &i);
			free(input_exp);
			input_exp = tmp;
			i = 0;
		}
		i++;
	}
	return (input_exp);
}
