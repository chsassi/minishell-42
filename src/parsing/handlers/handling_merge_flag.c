/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_merge_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:50 by mgalmari          #+#    #+#             */
/*   Updated: 2024/06/18 14:35:00 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_merge_flag_quote(char *input, int i)
{
	int	flag;

	flag = 0;
	if (i == 0)
		flag = 0;
	else if (input[i - 1] && (!check_spaces(input[i - 1]) ||
	(check_spaces(input[i]) == D_QUOTE && check_spaces(input[i - 1]) == S_QUOTE) ||
	(check_spaces(input[i]) == S_QUOTE && check_spaces(input[i - 1]) == D_QUOTE)))
		flag = MERGE_PREV;
	i += handle_quotes(&input[i]);
	if (input[i] && (!check_spaces(input[i]) || check_spaces(input[i]) == D_QUOTE
	|| check_spaces(input[i]) == S_QUOTE))
	{
		if (flag == MERGE_PREV)
			return (MERGE_BOTH);
		return (MERGE_NEXT);
	}
	return (flag);
}

int	find_merge_flag_dollar_sign(char *input, int i)
{
	int	flag;

	flag = 0;
	if (!input || !input[i])
		return (flag);
	if (i == 0)
		flag = 0;
	else if (input[i - 1] && (!check_spaces(input[i - 1]) 
	|| check_spaces(input[i - 1]) == D_QUOTE || check_spaces(input[i - 1]) == S_QUOTE))
		flag = MERGE_PREV;
	i += handle_operators(&input[i]);
	if (input[i] && (!check_spaces(input[i]) || check_spaces(input[i]) == D_QUOTE
	|| check_spaces(input[i]) == D_QUOTE))
	{
		if (flag == MERGE_PREV)
			return (MERGE_BOTH);
		return (MERGE_NEXT);
	}
	return (flag);
}

int	find_which_merge_flag(char *input, int i, int token)
{
	if (token == D_QUOTE || token == S_QUOTE)
		return (find_merge_flag_quote(input, i));
	else if (token == DOLLAR_SIGN)
		return (find_merge_flag_dollar_sign(input, i)); 
	return (0);
}

t_input	*switch_merge_flag(t_input *cmd_line, int token_nbr, int which_merge)
{
	int		i;
	t_input	*tmp;

	i = 0;
	tmp = cmd_line;
	while (tmp)
	{
		if (tmp->token == D_QUOTE || tmp->token == S_QUOTE || tmp->token == DOLLAR_SIGN)
		{
			if (i == token_nbr)
				tmp->merge = which_merge;
			i++;
		}
		tmp = tmp->next;
	}
	return (cmd_line);
}

t_input	*handle_merge_flag(char *input, t_input *cmd_line, int token_nbr, int i)
{
	int		token;
	int		which_flag;

	token = check_spaces(input[i]);
	which_flag = find_which_merge_flag(input, i, token);
	cmd_line = switch_merge_flag(cmd_line, token_nbr, which_flag);
	return (cmd_line);
}

t_input	*check_if_need_merge(t_parsing parsing, t_input *cmd_line)
{
	char	*input;
	int		i;
	int		token_nbr;

	i = 0;
	token_nbr = 0;
	input = parsing.input;
	while (input && input[i])
	{
		if (check_spaces(input[i]) == D_QUOTE || check_spaces(input[i]) == S_QUOTE
			|| check_spaces(input[i]) == DOLLAR_SIGN)
		{
			cmd_line = handle_merge_flag(input, cmd_line, token_nbr, i);
			token_nbr++;
			if (check_spaces(input[i]) == D_QUOTE || check_spaces(input[i]) == S_QUOTE)
				i += handle_quotes(&input[i]) - 1;
			else if (check_spaces(input[i]) == DOLLAR_SIGN)
				i += handle_operators(&input[i]) - 1;
		}
		i++;
	}
	return (cmd_line);
}
