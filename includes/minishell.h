/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:01:55 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/12 15:02:45 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "exec.h"
# include "libft.h"
# include "parser.h"
# include <readline/readline.h>
# include <readline/history.h>

extern int				g_exit;

typedef struct s_pars	t_pars;

typedef struct s_env
{
	char			*var;
	char			*content;
	bool			is_hidden;
	struct s_env	*next;
}	t_env;

typedef struct s_shell
{
	int				cmd_idx;
	char			**cmd;
	int				args_nbr;
	char			**redirects;
	int				fd_in;
	int				fd_out;
	char			*last_heredoc;
	struct s_shell	*next;
}	t_shell;

typedef struct s_all
{
	char	*input;
	t_shell	*shell;
	t_env	**env;
	int		**arr_pipe;
	int		cmd_nbr;
	int		restore_fd_in;
	int		restore_fd_out;
	int		status_code;
}	t_all;

// Init
void	check_input_loop(t_all *pAll, t_shell *pShell);
int		run_commands(t_all *pAll);
int		process_input(t_all *pAll);
bool	process_loop(t_all *pAll);
void	minishell_loop(t_env *env);

// Init Utils
void	input_check(t_all *pAll);
void	close_pipes_loop(t_all *pAll);

// Shell Init
int		count_pipes(t_pars *parser);
t_pars	*free_parse_until_pipe(t_pars *parser);
t_shell	*shell_init(t_pars **parser);

// Shell Utils
int		*init_pipes(t_all *pAll);
t_shell	*new_shell_node(t_pars **parser, int idx);
t_shell	*shell_last(t_shell *shell);
void	shell_add_back(t_shell **shell, t_shell *new);

void	free_shell(t_all *pAll);
void	free_all(t_all *pAll, bool should_exit, int status_code);

bool	is_valid_var(char *cmd, char *var);
void	close_fd(int fd);

#endif