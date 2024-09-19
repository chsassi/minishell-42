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

// Utils

<<<<<<< HEAD
t_env	*new_env_node(const char *env_var);

void	swap_nodes(t_env *a, t_env *b);
t_env	*sort_list(t_env *node);

=======
>>>>>>> fbb75f5b0f4482de4c8334639747f254120473b0
void	free_env_node(t_env *node);

#endif