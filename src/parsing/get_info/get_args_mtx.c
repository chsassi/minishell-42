/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_final_cmd_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:50 by mgalmari          #+#    #+#             */
/*   Updated: 2024/06/18 14:34:59 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_args(int *arr_token, char **mtx_cmdline, int index, char **args)
{
	int		j;
	int		size;

	j = 0;
	size = count_rows(mtx_cmdline);
	if ((index < size && arr_token[index] == CMD) && (mtx_cmdline && mtx_cmdline[index]))
		args[j++] = ft_strdup(mtx_cmdline[(index)++]);
	while ((index < size && arr_token[index] == ARG) && (mtx_cmdline && mtx_cmdline[index]))
		args[j++] = ft_strdup(mtx_cmdline[(index)++]);
	return (args);
}

char	**create_args_mtx(int *arr_token, char **mtx_cmdline, int *index)
{
	char	**args;
	int		size;

	args = NULL;
	size = 0;
	if (arr_token[*index] == CMD)
	{
		size = count_rows_args(&mtx_cmdline[*index], &arr_token[*index]);
		if (!size)
			return (free(arr_token), free_mtx(mtx_cmdline), NULL);
		args = ft_calloc(size + 1, sizeof(char *));
		if (!args)
			return (free(arr_token), free_mtx(mtx_cmdline), NULL);
		args = get_args(arr_token, mtx_cmdline, *index, args);
	}
	(*index)++;
	return (args);
}

t_input	*get_args_mtx(t_input *cmd_line)
{
	int		*arr_token;
	char	**mtx_cmdline;
	int		size;
	int		i;
	t_input	*tmp;

	i = 0;
	size = dll_input_size(cmd_line);
	mtx_cmdline = parsing_list_in_mtx(cmd_line);
	tmp = cmd_line;
	if (!mtx_cmdline || !size)
		return (dll_input_clear(&cmd_line), NULL);
	arr_token = get_arr_token(mtx_cmdline, size);
	while (tmp)
	{
		tmp->args = create_args_mtx(arr_token, mtx_cmdline, &i);
		if (!arr_token)
			return (dll_input_clear(&cmd_line), NULL);
		tmp = tmp->next;
	}
	free(arr_token);
	free_mtx(mtx_cmdline);
	return (cmd_line);
}
