/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_with_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:50 by mgalmari          #+#    #+#             */
/*   Updated: 2024/06/18 14:34:59 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_dollar_sign(char *str)
{
	int	i;
	int	dollar_signs;

	i = 0;
	dollar_signs = 0;
	while (str && str[i])
	{
		if (str[i] == '$')
			dollar_signs++;
		i++;
	}
	return (dollar_signs);
}

void    new_content_copy(char *new_content, char *content, char *env, int len)
{
    int i;
    int index;
    int len_word;

	i = 0;
    index = get_index_special_char(content, '$') + 1;
    len_word = get_len_word(content, index);
    while ((content && content[i]) && (i < index - 1))
	{
		new_content[i] = content[i];
		i++;
	}
	index = 0;
	len_word += i + 1;
	while ((env && env[index]) && (i < len))
	{
		new_content[i] = env[index++];
		i++;
	}
	while ((content && content[len_word]) && (i < len))
	{
		new_content[i] = content[len_word++];
		i++;
	}

}

char	*get_content_with_quotes(char *content, char *env)
{
	char	*new_content;
	int		i;
	int		len;
	int		index;
	int		len_word;

	i = 0;
	index = (get_index_special_char(content, '$') + 1);
	len_word = get_len_word(content, index) + 1;
	if (len_word == -1 || !env)
		return (NULL);
	len = (ft_strlen(content) - len_word) + ft_strlen(env);
	new_content = ft_calloc(len + 1, sizeof(char));
	if (!new_content)
		return (NULL);
	new_content_copy(new_content, content, env, len);
	free(content);
	return (new_content);
}
