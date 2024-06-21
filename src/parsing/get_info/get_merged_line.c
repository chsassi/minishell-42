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

int	*get_merge_arr(t_input *cmd_line, int *merge_arr, int size)
{
	t_input	*tmp;
	int		i;

	i = 0;
	tmp = cmd_line;
	while (tmp && i < size)
	{
		merge_arr[i] = tmp->merge;
		i++;
		tmp = tmp->next;
	}
	return (merge_arr);
}

int	*organize_merge_arr(int *merge_arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((merge_arr[i] == MERGE_PREV || merge[i] == MERGE_BOTH) && i != 0)
		{
			merge_arr[i - 1] = MERGE_NEXT;
			if (merge_arr[i] == MERGE_PREV)
				merge_arr[i] = STAY;
			else if (merge[i] == MERGE_BOTH)
				merge_arr[i] = MERGE_NEXT;
		}
		i++;
	}
	return (merge_arr);
}

char	*handle_merge_next(char	**mtx_cmdline, int *merge_arr, int *index)
{
	int		i;
	char	*content;

	i = *index;
	content = NULL;
	while (mtx_cmdline && mtx_cmdline[i])
	{
		if (mtx_cmdline[i + 1] && (i < size && merge_arr[i] == MERGE_NEXT))
		{
			content = ft_strjoin("\"", mtx_cmdline[i]);
			content = ft_strjoin(content, mtx_cmdline[i + 1]);
			
		}
		if (i + 1 < size && merge_arr[i + 1] == STAY)
		{
			content = ft_strjoin(content, "\"");
			break ;
		}
		i++;
	}
	index = &i;
}

char	*get_new_input(char	**mtx_cmdline, int *merge_arr, int size)
{
	int		i;
	char	*content;
	char	*new_input;

	i = 0;
	content = NULL;
	new_input = NULL;
	while ((mtx_cmdline && mtx_cmdline[i]) && i < size)
	{
		new_input = ft_strjoin(new_input, " ");
		if (merge_arr[i] == STAY)
			content = ft_strjoin(content, cmd_line->content);
		if (merge_arr[i] == MERGE_NEXT)
			content = handle_merge_next(mtx_cmdline, merge_arr, &i);
		if (!content)
			return (NULL);
		new_input = ft_strjoin(new_input, content);
		free(content);
		i++;
	}
}

char	*get_merged_line(t_input *cmd_line, int *merge_arr)
{
	char	*new_input;
	char	**mtx_cmdline;
	int		size;

	new_input = NULL;
	size = dll_input_size(cmd_line);
	mtx_cmdline = parsing_list_in_mtx(cmd_line);
	if (!merge_arr || !mtx_cmdline)
		return (NULL);
	merge_arr = get_merge_arr(cmd_line, merge_arr, size);
	merge_arr = organize_merge_arr(merge_arr, size);
	new_input = get_new_input(mtx_cmdline, merge_arr, size);
	free(merge_arr);
	free_mtx(mtx_cmdline);
	return (new_input);
}
