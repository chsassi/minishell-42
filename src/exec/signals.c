/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:53:07 by chsassi           #+#    #+#             */
/*   Updated: 2024/09/25 11:51:08 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ctrl-bckslsh
void	handle_sigquit(int signal)
{
	const char	*message;

	message = "^\\Quit (core dumped)\n";
	if (signal == SIGQUIT)
	{
		if (isatty(STDIN_FILENO))
			write(1, message, 20);
	}
	g_exit = 131;
}

//ctrl-c
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

//ctrl-d
void	handle_sigterm(int signal)
{
	if (signal == SIGTERM)
	{
		if (isatty(STDIN_FILENO))
			exit(0);
	}
}
