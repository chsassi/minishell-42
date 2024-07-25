#ifndef EXEC_H
# define EXEC_H

# include "libft.h"
# include "minishell.h"
# include "parser.h"
# include <sys/types.h>

typedef struct s_all	t_all;

// Builtins

void	run_pwd(t_all *pAll);
void	run_echo(t_all *pAll);
void	run_cd(t_all *pAll);
void	run_pwd(t_all *pAll);
void	run_export(t_all *pAll);
void	run_unset(t_all *pAll);
void	run_env(t_all *pAll);
void	run_exit(t_all *pAll);

// Signal Handling

void	handle_sigquit(int signal);
void	handle_sigint(int signal);
void	handle_eol(int signal);

#endif