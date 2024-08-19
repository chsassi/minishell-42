/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:57:34 by chsassi           #+#    #+#             */
/*   Updated: 2024/07/30 08:57:36 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "libft.h"
# include "minishell.h"
# include "parser.h"
# include <sys/types.h>

typedef struct s_all	t_all;

typedef struct s_exec
{
    char    **prompt;
    char    *abs_path;
    int     infile;
    int     outfile;
}   t_exec;

// Builtins

void	run_echo(t_all *pAll);
void	run_cd(t_all *pAll);
void	run_pwd(void);
void	run_export(t_all *pAll);
void	run_unset(t_all *pAll);
void	run_env(t_all *pAll);
void	run_exit(t_all *pAll);

// Signal Handling

void	handle_sigquit(int signal);
void	handle_sigint(int signal);
void	handle_eol(int signal);

#endif
