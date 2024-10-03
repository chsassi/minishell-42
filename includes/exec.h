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
# include <signal.h>
# include <sys/ioctl.h> 
# include <sys/types.h>
# include <sys/wait.h>

# define BUILTIN 9
# define REDIRECT_IN "<"
# define REDIRECT_OUT ">"
# define REDIRECT_APPEND ">>"
# define HEREDOC "<<"

typedef struct s_env	t_env;
typedef struct s_all	t_all;

// Builtins
void	cd_home(t_env *env_list);
void	cd_previous_dir(t_env *env_list);
void	cd_upper_dir(t_env *env_list);
void	cd_from_path(t_env *env_list, char *path);
void	bin_cd(t_env *env_list, char *path);
void	bin_echo(t_all *pAll);
t_env	*bin_env(t_env *current_env);
void	bin_exit(char **input);
void	bin_export(t_env **env_list, char **args);
void	bin_pwd(void);
t_env	*bin_unset(t_env **head, char *var_name);

// Exec
char	**get_path_from_env(void);
char	*find_executable_in_env(char **paths, char *command);
void	fork_cmd_process(char *cmd, char **mtx, char **envp);
int		run_builtin(char **args, t_env **env_list);
void	fork_cmd(char *cmd, char **mtx, char **envp);
void	run_exec(t_env *env, char **args);

// Heredoc & Redirects
void	restore_fds(int fd[2]);
void	handle_heredoc(char *delim);
void	handle_redirection(char *type, char *file, int fd[2]);

// Env Utils
t_env	*find_env_var(t_env *env_list, char *var);
void	update_env_var(t_env *env_list, char *var_name, char *new_value);
char	*get_env_var(t_env *env_list, char *var_name);
void	print_env(t_env *var);

// Export Utils
void	add_node_to_list(t_env **env_list, t_env *new_node);
void	handle_env_var(t_env **env_list, t_env *existing_var, \
char *var_name, char *equal_sign);
void	export_var(t_env **env_list, char *arg);
void	print_export(t_env *var);

// Mtx from Env
int		count_env_vars(t_env *env_list);
void	strjoin_loop(t_env *current, char **env_mtx, char *tmp);
char	**create_env_mtx(t_env *env_list);

// List Utils
void	set_var_content(t_env *new_node, char *equal_sign);
t_env	*new_env_node(char *env_var);
void	set_env_head(t_env **head, t_env *new_node, t_env **current);
t_env	*create_envp(char **envp);

// Signal Handling

// void	handle_sigquit(int signal);
void	handle_sigint(int signal);

#endif
