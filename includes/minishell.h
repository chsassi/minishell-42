/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:01:55 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/11 15:33:54 by brulutaj         ###   ########.fr       */
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
void	check_input_loop(t_all *pAll);
int		process_input(t_all *pAll);
void	minishell_loop(t_env *env);

// Init Utils
int		input_check(t_all *pAll);
void	close_pipes_loop(int **pipex, int cmd_nbr);

// Shell Init

int		count_pipes(t_pars *parser);
t_shell	*shell_init(t_pars *parser);

// Shell Utils

int		*init_pipes();
t_shell	*new_shell_node(t_pars *parser);
t_shell	*shell_last(t_shell *shell);
void	shell_add_back(t_shell **shell, t_shell *new);


#endif