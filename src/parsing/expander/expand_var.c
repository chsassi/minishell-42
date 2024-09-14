/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:52:46 by brulutaj          #+#    #+#             */
/*   Updated: 2024/09/14 16:54:18 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*new_exp_string(char *input_exp, t_env *envp, int *i)
{
	char	*first_str;
	char	*second_str;
	char	*third_str;
	char	*tmp_str;

	first_str = NULL;
	second_str = NULL;
	third_str = NULL;
	tmp_str = NULL;
	if ((*i) != 0)
		first_str = ft_substr(input_exp, 0, (*i));
	second_str = env_string(input_exp, i, envp);
	third_str = ft_substr(input_exp, (*i), ft_strlen(input_exp));
	free(input_exp);
	tmp_str = ft_strjoin_gnl(first_str, second_str);
	free(second_str);
	tmp_str= ft_strjoin_gnl(tmp_str, third_str);
	free(third_str);
	return(tmp_str);
}

char	*expansion(char *input, t_env *envp)
{
	char	*input_exp;
	int		i;

	i = 0;
	input_exp = ft_strdup(input);
	while (input_exp && input_exp[i] != '\0')
	{
		if (input[i] == '\'')
			i += quote_token_length(input + i);
		if (input_exp[i] == '$')
		{
			input_exp = new_exp_string(input_exp, envp, &i);
		}
		i++;
	}
	return (input_exp);
}
