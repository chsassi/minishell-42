/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:09:34 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/12 18:40:20 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*init_pipes(t_all *pAll)
{
	int	*arr;

	arr = (int *)ft_calloc(2, sizeof(int));
	if (!arr)
		return (free(arr), free_all(pAll, true, 1), NULL);
	if (pipe(arr) == -1)
		return (free(arr), free_all(pAll, true, 1), NULL);
	return (arr);
}

t_shell	*new_shell_node(t_pars **parser, int idx)
{
	t_shell	*new;

	new = (t_shell *)ft_calloc(1, sizeof(t_shell));
	if (!new)
		return (NULL);
	new->cmd_idx = idx;
	new->redirects = red_mtx(parser);
	new->cmd = cmd_mtx(*parser);
	new->args_nbr = ft_rowlen(new->cmd);
	new->fd_in = -1;
	new->fd_out = -1;
	new->last_heredoc = NULL;
	new->next = NULL;
	return (new);
}

t_shell	*shell_last(t_shell *shell)
{
	if (!shell)
		return (NULL);
	while (shell)
	{
		if (shell->next == NULL)
			return (shell);
		shell = shell->next;
	}
	return (shell);
}

void	shell_add_back(t_shell **shell, t_shell *new)
{
	t_shell	*tmp;

	if (!shell | !new)
		return ;
	if (!(*shell))
	{
		*shell = new;
		return ;
	}
	tmp = shell_last(*shell);
	tmp->next = new;
}
