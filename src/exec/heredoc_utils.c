/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:21:32 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/13 19:21:34 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*heredoc_expand(t_all *all, t_exp p)
{
	t_helper	tmp;

	tmp = (t_helper){0};
	(void)all;
	if (*p.i != 0)
		tmp.first_str = ft_substr(p.inp, 0, *p.i);
	tmp.second_str = env_string(all, p.inp, p.i, p.env);
	tmp.third_str = ft_strdup(p.inp + (*p.i));
	*p.i = 0;
	tmp.result = ft_strjoin_gnl(tmp.first_str, tmp.second_str);
	*p.i += ft_strlen(tmp.result);
	free(tmp.second_str);
	tmp.result = ft_strjoin_gnl(tmp.result, tmp.third_str);
	free(tmp.third_str);
	return (free(p.inp), tmp.result);
}

char	*heredoc_expansion(t_all *all, char *value)
{
	char			*input_exp;
	int				i;

	i = 0;
	input_exp = value;
	while (input_exp && *input_exp && input_exp[i] != '\0')
	{
		if (input_exp && input_exp[i] && input_exp[i] == '$')
			input_exp = heredoc_expand(all,
					(t_exp){input_exp, *all->env, &i, GENERAL});
		if (input_exp && input_exp[i] && input_exp[i] == '\0')
			break ;
		if (input_exp && input_exp[i] && input_exp[i] != '$')
			i++;
	}
	return (input_exp);
}
