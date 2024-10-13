/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:53:05 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/13 16:25:45 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_escaped_char(int c)
{
	if (c == '\'' || c == '\"' || c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}

char	*process_escaped(char *str, int *i)
{
	char	*tmp;
	int		len;

	tmp = NULL;
	len = 0;
	tmp = malloc(sizeof(char) * 4);
	if (!tmp)
		return (NULL);
	if (*str == '\'')
	{
		tmp[len] = '\"';
		tmp[len + 1] = *str;
		tmp[len + 2] = '\"';
	}
	else
	{
		tmp[len] = '\'';
		tmp[len + 1] = *str;
		tmp[len + 2] = '\'';
	}
	tmp[len + 3] = '\0';
	(*i)++;
	return (tmp);
}

char	*create_escaped_str(char *content, int *i)
{
	char	*front_str;
	char	*escaped_str;
	char	*back_str;
	char	*result;

	front_str = NULL;
	escaped_str = NULL;
	back_str = NULL;
	result = NULL;
	if ((*i) != 0)
		front_str = ft_substr(content, 0, (*i));
	else
		front_str = ft_strdup("");
	escaped_str = process_escaped(content + (*i), i);
	back_str = ft_strdup(content + (*i));
	*i = 0;
	result = ft_strjoin_gnl(front_str, escaped_str);
	*i += ft_strlen(result) - 1;
	free(escaped_str);
	result = ft_strjoin_gnl(result, back_str);
	free(back_str);
	return (result);
}

char	*processed_str_exp(char *content)
{
	char	*new;
	int		i;

	i = 0;
	new = content;
	while (content[i] != '\0')
	{
		if (is_escaped_char(content[i]))
		{
			new = create_escaped_str(content, &i);
			free(content);
			content = new;
		}
		if (content[i] == '\0')
			return (new);
		i++;
	}
	return (new);
}

int	check_expansion(char *input, int *i)
{
	int	j;

	j = (*i);
	while ((*i) != 0 && input[(*i) - 1] && ft_isspace(input[(*i) - 1]))
		(*i)--;
	if ((*i) != 0 && input[(*i) - 1] == '<')
	{
		(*i)--;
		if ((*i) != 0 && input[(*i) - 1] == '<')
		{
			(*i) = j + 1;
			return (0);
		}
	}
	(*i) = j;
	return (1);
}
