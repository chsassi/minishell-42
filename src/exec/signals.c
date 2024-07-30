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
void	handle_sigquit(int signal);
//- nothing if not fd 0
//- ^\[1]    630380 quit (core dumped)

// ctrl-c
void	handle_sigint(int signal);
//- re-prompt
//- ^C if fd 0

// ctrl-d
void	handle_sigterm(int signal);
//- quits shell
//- re-prompt if fd 0
