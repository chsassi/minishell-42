/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:53:05 by brulutaj          #+#    #+#             */
/*   Updated: 2024/09/20 12:05:35 by brulutaj         ###   ########.fr       */
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
	while (is_escaped_char(str[len]))
		len++;
	(*i) += len;
	len = 0;
	tmp = malloc(sizeof(char) * len + 3);
	if (!tmp)
		return (NULL);
	tmp[len] = '*';
	len++;
	while (is_escaped_char(str[len]))
	{
		tmp[len] = str[len];
		len++;
	}
	tmp[len] = '*';
	tmp[len + 1] = '\0';
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
	if ((*i) != 0)
		front_str = ft_substr(content, 0, (*i));
	else
		front_str = ft_strdup("");
	escaped_str = process_escaped(content[*i], *i);
	back_str = ft_strdup(content + (*i));
	*i = 0;
	result = ft_strchr_gnl(front_str, escaped_str);
	*i += ft_strlen(result);
}

char	*processed_str_exp(char *content)
{
	char	*new;
	int		i;

	i = 0;
	while (content[i] != '\0')
	{
		if (is_escaped_char(content[i]))
			new = 
	}
}

