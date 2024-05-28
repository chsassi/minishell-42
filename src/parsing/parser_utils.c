#include "minishell.h"

int	check_spaces(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else if (c == '\"')
		return (D_QUOTE);
	else if (c == '\'')
		return (S_QUOTE);
	else if (c == '|' || c == '<' || c == '>')
		return (PIPE);
	return (0);
}

int	handle_quotes(char *s, int *index)
{
	int	i;

	i = 0;
	if (!s || !s[i])
		return (0);
	if (check_spaces(s[i]) == D_QUOTE)
	{
		i = 1;
		while (s[i] && check_spaces(s[i]) != D_QUOTE)
			i++;
	}
	else if (check_spaces(s[i]) == S_QUOTE)
	{
		i = 1;
		while (s[i] && check_spaces(s[i]) != S_QUOTE)
			i++;
	}
	if (!s[i])
		return (-1);
	*index += i;
	return (0);
}

static int	handle_not_spaces(char *s, int *word_num)
{
	int	i;

	i = 0;
	if (check_spaces(s[i]) == D_QUOTE || check_spaces(s[i]) == S_QUOTE)
	{
		if (handle_quotes(&s[i], &i) == -1)
			return (-1);
		i++;
	}
	while (s[i] && (!check_spaces(s[i]) || check_spaces(s[i]) == PIPE))
	{
		if (check_spaces(s[i]) == PIPE)
		{
			if (s[i - 1] && check_spaces(s[i - 1]) != 1)
				(*word_num)++;
			if (check_spaces(s[i + 1]) == PIPE)
				i++;
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

int	count_words(char *s)
{
	int	i;
	int	tmp;
	int	word_num;

	i = 0;
	word_num = 0;
	tmp = 0;
	while (s && s[i])
	{
		while (s[i] && check_spaces(s[i]) == 1)
			i++;
		if (s[i])
			word_num++;
		if (s[i] && (!check_spaces(s[i]) || check_spaces(s[i]) == PIPE))
			tmp = handle_not_spaces(&s[i], &word_num);
		if (tmp == -1)
			return (-1);
		i += tmp;
	}
	return (word_num);
}

static int	word_len(char *s)
{
	int	i;

	i = 0;
	if (s[i] && check_spaces(s[i]) == PIPE)
	{
		if (s[i + 1] && check_spaces(s[i + 1]) == PIPE)
			return (2);
		return (1);
	}
	if (s[i] && (check_spaces(s[i]) == 7 || check_spaces(s[i]) == 8))
		return (handle_quotes(s, &i));
	while (s[i] && !check_spaces(s[i]))
		i++;
	return (i);
}

char	**new_string(char **mtx, char *s)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		while (*s && check_spaces(*s) == 1)
			s++;
		if (*s)
		{
			if (*s && check_spaces(*s) != 1)
				len = word_len(s);
			mtx[i] = ft_substr(s, 0, len);
			if (!mtx[i])
			{
				free_mtx(mtx);
				return (NULL);
			}
			i++;
			s += len;
		}
	}
	mtx[i] = NULL;
	return (mtx);
}
