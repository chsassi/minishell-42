#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "parser.h"
# include <signal.h>

// Signal Handling

void	handle_sigquit(int signal);
void	handle_sigint(int signal);
void	handle_eol(int signal);

#endif