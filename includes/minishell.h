/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:01:55 by chsassi           #+#    #+#             */
/*   Updated: 2024/07/30 08:57:36 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "exec.h"
# include "libft.h"
# include "parser.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_elem	t_elem;

typedef struct s_envp
{
	char 			*str;
	struct s_envp	*next;
}	t_envp;

typedef struct s_all
{
	t_elem	*node;
	t_envp	*envp;
	char	*path;
	int		size;
}	t_all;

#endif
