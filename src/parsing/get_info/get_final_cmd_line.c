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

t_input	*create_cmdline_with_cmds(t_input *cmd_line)
{
	t_input	*head;
	t_input	*new_node;

	head = NULL;
	new_node = NULL;
	while (cmd_line)
	{
		if (check_if_operator(cmd_line->token))
		{
			new_node = dll_input_new(cmd_line->content);
			if (!new_node)
				return (dll_input_clear(&head), NULL);
			new_node->token = cmd_line->token;
			dll_input_addback(&head, new_node);
		}
		cmd_line = cmd_line->next;
	}
	return (head);
}

char	**create_args_mtx_from_lst(t_input **head)
{
	int		size;
	int		i;
	char	**args;

	args = NULL;
	i = 0;
	if ((*head)->token == CMD)
	{
		size = count_nbr_args((*head)->next);
		if (!size)
			return (NULL);
		args = ft_calloc(size + 1, sizeof(char *));
		if (!args)
			return (NULL);
		(*head) = (*head)->next;
		while ((*head) && (*head)->token == ARG)
		{
			args[i] = ft_strdup((*head)->content);
			if (!args[i])
				return (free_mtx(args), NULL);
			i++;
			(*head) = (*head)->next;
		}
		args[i] = NULL;
	}
	else
		*head = (*head)->next;
	return (args);
}

t_input	*get_args_mtx(t_input *new_cmdline, t_input *cmd_line)
{
	t_input	*tmp;

	tmp = new_cmdline;
	while (tmp)
	{
		tmp->args = create_args_mtx_from_lst(&cmd_line);
		tmp = tmp->next;
	}
	return (new_cmdline);
}
