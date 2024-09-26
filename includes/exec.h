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

// CD
void	cd_home(t_env *env_list);
void	cd_previous_dir(t_env *env_list);
void	cd_upper_dir(t_env *env_list);
void	cd_from_path(t_env *env_list, char *path);
void	bin_cd(t_env *env_list, char *path);

// ECHO
void	bin_echo(t_all *pAll);

// ENV
t_env	*bin_env(t_env *current_env/* t_all *pAll */);

// EXIT
void	bin_exit(char **input/* t_all *pAll */);

// EXPORT
void	bin_export(t_all *pAll);

// PWD
void	bin_pwd(void);

// UNSET
t_env	*bin_unset(t_env **head, char *var_name);

// Exec
char	**get_path_from_env(void/* t_all *pAll */);
char	*find_executable_in_env(char **paths, char *command);
void	fork_cmd_process(char *cmd, char **mtx, char **envp);
int		run_exec(t_all *pAll);

// Heredoc
void	handle_heredoc(char *delim);

#endif
