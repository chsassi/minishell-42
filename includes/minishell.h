/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:01:55 by chsassi           #+#    #+#             */
/*   Updated: 2024/09/26 15:28:56 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "exec.h"
# include "libft.h"
# include "parser.h"
# include <readline/readline.h>
# include <readline/history.h>

extern int	g_exit;

typedef struct s_env
{
	char			*var;
	char			*content;
	bool			is_hidden;
	struct s_env	*next;
}	t_env;

typedef struct s_shell
{
	char			**cmd;
	char			**redirects;
	int				fd_in; // start from -1
	int				fd_out; // start from -1
	char			*last_heredoc;
	struct s_shell	*next;
}	t_shell;

// Init
void	check_redirection(char **args, int fd[2]);
int		process_input(char *input, t_env **env, int fd[2]);
void	minishell_loop(char *input, t_env *env);

// Waste
void	write_mtx2(char **mtx, int *arr);
char	*arr_int_str(int i);

#endif