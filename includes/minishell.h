/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:01:55 by chsassi           #+#    #+#             */
/*   Updated: 2024/09/13 18:35:15 by brulutaj         ###   ########.fr       */
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

typedef struct s_elem	t_elem;

typedef struct s_env
{
	char			*var;
	char			*content;
	bool			is_hidden;
	struct s_env	*next;
}	t_env;

typedef struct s_all
{
	char			**prompt;
	t_env			*envp;
	unsigned char	status_code;
}	t_all;

// Env Utils
t_env	*find_env_var(t_env *env_list, char *var);
void	update_env_var(t_env *env_list, char *var_name, char *new_value);
char	*get_env_var(t_env *env_list, char *var_name);
void	free_env_node(t_env *node);

// List Utils
t_env	*create_envp(char **envp);
t_env	*new_env_node(const char *env_var);
void	swap_env_nodes(t_env *a, t_env *b);

// Signal Handling
void	handle_sigquit(int signal);
void	handle_sigint(int signal);
void	handle_sigterm(int signal);

#endif