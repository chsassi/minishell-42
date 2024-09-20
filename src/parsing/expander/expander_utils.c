/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:53:05 by brulutaj          #+#    #+#             */
/*   Updated: 2024/09/19 17:00:01 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_escaped_char(int c)
{
	if (c == '\'' || c == '\"' || c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}

char	*escped_str(char *s, int *i)
{
	char	*tmp;
	int		len;
	
	tmp = NULL;
	len	= 0;
	while (is_escaped_char(s[*i]))
	{
		(*i)++;
		len++;
	}
}

char	*create_escaped_str(char *content, char *new, int *i)
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
	escaped_str = 
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

