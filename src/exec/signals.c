/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:53:07 by chsassi           #+#    #+#             */
/*   Updated: 2024/07/30 09:53:09 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ctrl-bckslsh
/*** need to be added only when fd is 0 in execution part ***/
void	handle_sigquit(int signal)
{
	const char	*message;

	message = "^\\Quit (core dumped)\n";
	if (signal == SIGQUIT)
	{
		if (isatty(STDIN_FILENO))
			write(1, message, 20);
	}
}

//ctrl-c
void	handle_sigint(int signal)
{
	if (signal == SIGINT)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\nminishell> ", 12);
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
