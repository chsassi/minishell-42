/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:57:34 by chsassi           #+#    #+#             */
/*   Updated: 2024/10/07 16:38:45 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "libft.h"
# include "minishell.h"
# include "parser.h"
# include <signal.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/wait.h>

# define REDIRECT_IN "<"
# define REDIRECT_OUT ">"
# define REDIRECT_APPEND ">>"
# define HEREDOC "<<"

typedef struct s_env	t_env;
typedef struct s_exp	t_exp;
typedef struct s_shell	t_shell;
typedef struct s_pars	t_pars;
typedef struct s_all	t_all;

// Builtins
void	cd_home(t_all *pAll);
void	cd_previous_dir(t_all *pAll);
void	cd_upper_dir(t_all *pAll);
void	cd_from_path(t_all *pAll, char *path);
void	bin_cd(t_all *pAll, t_shell *pShell);
int		newline_check(t_shell *pShell, int i, bool *nl);
void	bin_echo(t_all *pAll, t_shell *pShell);
t_env	*bin_env(t_all *pAll);
bool	is_numeric(char *str);
int		check_exit_params(t_all *pAll, t_shell *pShell);
void	bin_exit(t_all *pAll, t_shell *pShell);
void	bin_export(t_all *pAll, t_shell *pShell);
void	bin_pwd(t_all *pAll);
bool	unset_check_head(t_all *pAll, char *variable);
bool	unset_check_all(t_all *pAll, char *variable);
t_env	*bin_unset(t_all *pAll, t_shell *pShell);

// Exec
void	exec_cmd(t_all *pAll, char *cmd, char **args, char **envp);
void	fork_cmd(t_all *pAll, char *cmd, char **args, char **envp);
int		run_builtin(t_all *pAll, t_shell *pShell);
char	*access_exec(t_all *pAll, t_shell *pShell, bool inside_fork);
bool	run_exec(t_all *pAll, t_shell *pShell, bool inside_fork);

// Exec Utils
char	**get_path_from_env(t_all *pAll);
char	*find_executable_in_env(char **paths, char *command);

// Heredoc
bool	heredoc_loop(t_all *pAll, char *delim, int fd);
bool	handle_heredoc(t_all *pAll, char *delim, char *filename);
bool	is_last_heredoc(t_shell *shell, int red_idx);
bool	parse_shell_heredoc(t_all *pAll, t_shell *curr, int red_idx);
bool	exec_heredocs(t_all *pAll);

// Heredoc Utils

char	*heredoc_expand(t_all *pAll, t_exp pExp);
char	*heredoc_expansion(t_all *pAll, char *value);

// Redirect
void	restore_fds(t_all *pAll);
int		handle_redirection_open(char *type, char *file);
int		handle_redirection(t_all *pAll, char *type, char *file);
bool	exec_redirection(t_all *pAll, t_shell *pShell);

// Signal
void	print_nl_on_sigint(int sig);
void	handle_heredoc_sigint(int sig);
void	set_status_from_sig(t_all *pAll, int sig);
void	handle_sigint(int signal);

// Env Utils
t_env	*find_env_var(t_env *env_list, char *var);
bool	update_env_var(t_env **env_list, char *var_name, char *new_value);
char	*get_env_var(t_env *env_list, char *var_name);
void	print_env(t_env *var);

// Export Utils
void	add_node_to_list(t_env **env_list, t_env *new_node);
void	handle_env_var(t_env **env_list, t_env *existing_var, \
char *var_name, char *equal_sign);
bool	export_var(t_all *pAll, char *arg);
void	print_export(t_env *var);

// Mtx from ENV
int		count_env_vars(t_env *env_list);
void	strjoin_loop(t_env *current, char **env_mtx, char *tmp);
char	**create_env_mtx(t_env *env_list);

// List Utils
void	set_var_content(t_env *new_node, char *equal_sign);
t_env	*new_env_node(char *env_var);
void	set_env_head(t_env **head, t_env *new_node, t_env **current);
t_env	*create_envp(char **envp);
void	handle_pipe_dups(t_all *pAll, t_shell *pShell);

#endif
