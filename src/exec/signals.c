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

void	handle_heredoc_sigint(int sig)
{
	g_exit = sig; 
	ioctl(0, TIOCSTI, "\n");
	// write(2, "\n", 1);
	// if (sig == SIGINT)
	// {
	// 	rl_replace_line("", 0);
	// 	rl_redisplay();
	// }
}

void	set_status_from_sig(t_all *pAll, int sig)
{
	if (g_exit == -42)
		return ;
	if (sig == SIGINT)
		pAll->status_code = 130;
	else if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)\n", 2);
		pAll->status_code = 131;
	}
}

void	handle_sigint(int signal)
{
	g_exit = signal;
	if (signal == SIGINT)
	{
		ioctl(0, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		// write(1, "\nminishell> ", 12);
		// rl_redisplay();
	}
}
