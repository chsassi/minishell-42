/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:53:07 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 18:40:20 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_status_from_sig(t_all *pAll, int sig)
{
	if (sig == SIGINT)
		pAll->status_code = 130;
	else if (sig == SIGQUIT)
		pAll->status_code = 131;
}

void	handle_sigint(int signal)
{
	if (signal == SIGINT)
	{
		rl_replace_line("", 0);
		write(1, "\nminishell> ", 12);
		rl_redisplay();
		g_exit = 130;
	}
}
