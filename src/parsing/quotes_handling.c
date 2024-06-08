#include "minishell.h"

int	find_which_merge_flag(char *input, int i)
{
	int	flag;

	flag = 0;
	if (input[i - 1] && (!check_spaces(input[i - 1]) ||
	(check_spaces(input[i]) == D_QUOTE && check_spaces(input[i - 1]) == S_QUOTE) ||
	(check_spaces(input[i]) == S_QUOTE && check_spaces(input[i - 1]) == D_QUOTE)))
		flag = MERGE_PREV;
	i += handle_quotes(&input[i]);
	if (input[i] && (!check_spaces(input[i]) || check_spaces(input[i]) == D_QUOTE
	|| check_spaces(input[i]) == D_QUOTE))
	{
		if (flag == MERGE_PREV)
			return (MERGE_BOTH);
		return (MERGE_NEXT);
	}
	return (flag);
}

t_input	*switch_merge_flag(t_input *cmd_line, int quote_nbr, int which_merge)
{
	int		i;
	t_input	*tmp;

	i = 0;
	tmp = cmd_line;
	while (tmp)
	{
		if (tmp->token == D_QUOTE || tmp->token == S_QUOTE)
		{
			if (i == quote_nbr)
				tmp->merge = which_merge;
			i++;
		}
		tmp = tmp->next;
	}
	return (cmd_line);
}

t_input	*check_if_need_merge(t_parsing parsing, t_input *cmd_line)
{
	char	*input;
	int		i;
	int		quote_nbr;
	int		which_flag;

	i = 0;
	quote_nbr = 0;
	which_flag = 0;
	input = parsing.input;
	while (input && input[i])
	{
		if (check_spaces(input[i]) == D_QUOTE || check_spaces(input[i]) == S_QUOTE)
		{
			which_flag = find_which_merge_flag(input, i);
			cmd_line = switch_merge_flag(cmd_line, quote_nbr, which_flag);
			quote_nbr++;
			i += (handle_quotes(&input[i]) - 1);
		}
		i++;
	}
	return (cmd_line);
}
