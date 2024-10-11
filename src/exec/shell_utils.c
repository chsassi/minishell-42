/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:09:34 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/11 16:49:27 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*init_pipes()
{
	int	*arr;

	arr = (int *)malloc(2 * sizeof(int));
	if (!arr)
		return (NULL);
	arr[0] = dup(STDIN_FILENO);
	arr[1] = dup(STDOUT_FILENO);
	return(arr);
}

t_shell	*new_shell_node(t_pars *parser)
{
	t_shell	*new;

	new = (t_shell *)malloc(sizeof(t_shell));
	if (!new)
		return(NULL);
	new->cmd = cmd_mtx(parser);
	new->redirects = red_mtx(parser);
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
	t_shell *tmp;
	
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
