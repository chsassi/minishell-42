/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:52:46 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/11 15:00:52 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*exp_string(char *inp, t_env *env, int *i, enum e_state state)
{
	t_helper	tmp;

	tmp = (t_helper){0};
	if ((*i) != 0)
		tmp.first_str = ft_substr(inp, 0, (*i));
	else
		tmp.first_str = ft_strdup("");
	if (state == GENERAL)
		tmp.second_str = processed_str_exp(env_string(inp, i, env));
	else
		tmp.second_str = env_string(inp, i, env); 
	tmp.third_str = ft_strdup(inp + (*i));
	*i = 0;
	tmp.result = ft_strjoin_gnl(tmp.first_str, tmp.second_str);
	*i += ft_strlen(tmp.result);
	free(tmp.second_str);
	tmp.result= ft_strjoin_gnl(tmp.result, tmp.third_str);;
	free(tmp.third_str);
	return(free(inp), tmp.result);
}

char	*expansion(char *input, t_env *envp)
{
	char			*input_exp;
	int				i;
	enum e_state	state;

	i = 0;
	state = GENERAL;
	input_exp = ft_strdup(input);
	while (input_exp && *input_exp && input_exp[i] != '\0')
	{
		if (input_exp && input_exp[i] && input_exp[i] == '\'')
			i += quot_tok_len(input_exp + i);
		if (input_exp && input_exp[i] && input_exp[i] == '\"')
			set_state(&state);
		if (input_exp && input_exp[i] && input_exp[i] == '$')
			input_exp = exp_string(input_exp, envp, &i, state);
		if (input_exp && input_exp[i] && input_exp[i] == '\0')
			break;
		if(input_exp && input_exp[i] && input_exp[i] != '$')
			i++;
	}
	free(input);
	return (input_exp);
}

char	*find_env_string(char *input, t_env *envp, int len)
{
	t_env	*tmp;
	char	*substring;
	
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
			return (ft_itoa(g_exit));
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

void	set_state(enum e_state *state)
{
	if ((*state) == GENERAL)
		(*state) = IN_DQUOTE;
	else
		(*state) = GENERAL;
}
