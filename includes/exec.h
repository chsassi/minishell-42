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

typedef struct s_env	t_env;
typedef struct s_all	t_all;

// Builtins

char	*get_env_var(t_env *env_list, char *var_name);
void	cd_upper_dir(t_env *env_list);
void	cd_previous_dir(t_env *env_list);
void	cd_home(t_env *env_list);
void	bin_cd(t_env *env_list, char *path);

void	bin_echo(t_all *pAll);
t_env	*bin_env(t_env *current_env/* t_all *pAll */);
void	bin_exit(char **input/* t_all *pAll */);


t_env	*find_env_var(t_env *env_list, char *var);
void	update_env_var(t_env *env_list, char *var_name, char *new_value);

void	bin_export(t_all *pAll);
void	bin_pwd(void);
t_env	*bin_unset(t_env **head, char *var_name);

// Environment

t_env	*create_envp(char **envp);
t_env	*new_env_node(const char *env_var);
void	swap_env_nodes(t_env *a, t_env *b);

// Signal Handling

void	handle_sigquit(int signal);
void	handle_sigint(int signal);
void	handle_sigterm(int signal);

// Exec

char	**get_path_from_env(void/* t_all *pAll */);
char	*find_executable_in_env(char **paths, char *command);
void	fork_cmd_process(char *cmd, char **mtx, char **envp);
void	execute_command(t_all *pAll);
int		run_exec(t_all *pAll);

#endif
