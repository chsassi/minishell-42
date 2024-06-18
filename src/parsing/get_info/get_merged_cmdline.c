/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_merged_cmdline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:50 by mgalmari          #+#    #+#             */
/*   Updated: 2024/06/18 14:34:59 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_merged_cmdline(t_input *cmd_line)
{
	t_input *tmp;
	char	*new_input;

	tmp = cmd_line;
	new_input = NULL;
	while (tmp)
	{
		if (tmp->prev && (tmp->merge == STAY && (tmp->prev->merge == MERGE_NEXT ||
		tmp->prev->merge == MERGE_BOTH)))
		{
			new_input = ft_strjoin(new_input, tmp->content);
			if (tmp->next)
				tmp = tmp->next;
		}
		if (tmp->merge == STAY || tmp->merge == MERGE_NEXT)
			new_input = ft_strjoin(new_input, " ");
		if (tmp->merge == STAY)
			new_input = ft_strjoin(new_input, tmp->content);
		if (tmp->merge == MERGE_PREV)
			new_input = ft_strjoin(new_input, tmp->content);
		if (tmp->merge == MERGE_NEXT || tmp->merge == MERGE_BOTH)
		{
			new_input = ft_strjoin(new_input, tmp->content);
			new_input = ft_strjoin(new_input, tmp->next->content);
			if (tmp->next)
				tmp = tmp->next;
		}
		if (!tmp)
			break ;
		tmp = tmp->next;
	}
	return (new_input);
}
