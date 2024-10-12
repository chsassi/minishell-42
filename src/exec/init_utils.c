/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:40:15 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 18:40:20 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_check(t_all *pAll)
{
	if (!pAll->input)
	{
		write(1, "exit\n", 6);
		free_all(pAll, true, pAll->status_code);
	}
}

void	close_pipes_loop(t_all *pAll)
{
	int	i;

	i = 0;
	while (i < pAll->cmd_nbr && pAll->arr_pipe && pAll->arr_pipe[i])
	{
		close(pAll->arr_pipe[i][0]);
		close(pAll->arr_pipe[i][1]);
		free(pAll->arr_pipe[i]);
		i++;
	}
	free(pAll->arr_pipe);
	pAll->arr_pipe = NULL;
}
