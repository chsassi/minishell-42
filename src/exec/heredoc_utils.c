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

char	*heredoc_expand(t_all *pAll, t_exp pExp)
{
	t_helper	tmp;

	tmp = (t_helper){0};
	(void)pAll;
	if (*pExp.i != 0)
		tmp.first_str = ft_substr(pExp.inp, 0, *pExp.i);
	tmp.second_str = env_string(pAll, pExp.inp, pExp.i, pExp.env);
	tmp.third_str = ft_strdup(pExp.inp + (*pExp.i));
	*pExp.i = 0;
	tmp.result = ft_strjoin_gnl(tmp.first_str, tmp.second_str);
	*pExp.i += ft_strlen(tmp.result);
	free(tmp.second_str);
	tmp.result = ft_strjoin_gnl(tmp.result, tmp.third_str);
	free(tmp.third_str);
	return (free(pExp.inp), tmp.result);
}

char	*heredoc_expansion(t_all *pAll, char *value)
{
	char			*input_exp;
	int				i;

	i = 0;
	input_exp = value;
	while (input_exp && *input_exp && input_exp[i] != '\0')
	{
		if (input_exp && input_exp[i] && input_exp[i] == '$')
			input_exp = heredoc_expand(pAll,
					(t_exp){input_exp, *pAll->env, &i, GENERAL});
		if (input_exp && input_exp[i] && input_exp[i] == '\0')
			break ;
		if (input_exp && input_exp[i] && input_exp[i] != '$')
			i++;
	}
	return (input_exp);
}
