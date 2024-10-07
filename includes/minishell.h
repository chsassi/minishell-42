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
	char			*input;
	char			**cmd;
	char			**redirects;
	int				*pipe;
	int				fd_in; // start from -1
	int				fd_out; // start from -1
	int				cmd_id;
	char			*last_heredoc;
	struct s_shell	*next;
}	t_shell;

typedef struct s_all
{
	t_shell	shell;
	t_env	**env;
	int		cmd_nbr;
	int		restore_fd_in;
	int		restore_fd_out;
	int		status_code;
}	t_all;

// Init
void	check_input_loop(t_all *pAll, t_shell *shell);
int		process_input(char *input, t_env **env, int fd_in, int fd_out);
void	minishell_loop(t_env *env);

// Waste
void	write_mtx2(char **mtx, int *arr);
char	*arr_int_str(int i);

#endif