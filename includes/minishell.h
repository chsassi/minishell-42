/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:33:51 by mgalmari          #+#    #+#             */
/*   Updated: 2024/06/18 14:33:54 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "parsing.h"
//# include "builtin.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <term.h>
# include <curses.h>
# include <signal.h>

// # define ECHO "echo";
# define CD "cd";
# define PWD "pwd";
# define EXPORT "export";
# define UNSET "unset";
# define ENV "env";
# define EXIT "exit";

typedef struct	s_all	t_all;

typedef enum	e_quotes t_quotes;

typedef enum	e_token t_token;

typedef struct	s_input
{
	char			*content;
	char			**args;
	int				token;
	int				merge;
	struct s_input	*next;	
	struct s_input	*prev;
}	t_input;

typedef struct	s_all
{
	t_list		*envp;
	t_input		*cmd_line;
}	t_all;

// --- Execution --- //
// Built-ins
//void		builtin_pwd(t_builtin	*pBuiltin);
//int			builtin_exit(t_all *pAll);
//void	builtin_env(t_builtin *pBuiltin);

// Free_exit_handling
void		free_parsing(t_parsing *parsing);
void		set_clear_all(t_all *all);
void		free_all(t_all *all);
void		close_all(t_all *all);

// Lst_input_handling
void		dll_input_addback(t_input **lst, t_input *new);
void		dll_input_addfront(t_input **lst, t_input *new);
void		dll_input_clear(t_input **lst);
t_input		*dll_input_last(t_input *lst);
t_input		*dll_input_new(char *content);
int			dll_input_size(t_input *lst);

#endif