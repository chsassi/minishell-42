
#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <term.h>
# include <curses.h>

// # define ECHO "echo";
# define CD "cd";
# define PWD "pwd";
# define EXPORT "export";
# define UNSET "unset";
# define ENV "env";
# define EXIT "exit";

typedef struct	s_all	t_all;

typedef enum	e_token
{
	WORDS,
	DOLLAR_SIGN,
	PIPE,
	REDIRECT_INPUT,
	REDIRECT_OUTPUT,
	D_RED_INPUT,
	D_RED_OUTPUT,
	D_QUOTE,
	S_QUOTE,
}	t_token;

typedef struct	s_dll_input
{
	char				*content;
	char				*path;
	int					token;
	int					index;
	struct s_dll_input	*next;	
	struct s_dll_input	*prev;
}	t_dll_input;

typedef struct	s_parsing
{
	char	*input;
	char	**mtx_from_input;
	int		*arr_token;
}	t_parsing;

typedef struct	s_builtin
{
	char	*path;

}	t_builtin;

typedef struct	s_all
{
	t_builtin	ptr;
}	t_all;

int	count_words(char *s);

// Parsing
void	parse_input(char *input);

// Parse_utils
int			check_spaces(char c);
char		**new_string(char **mtx, char *s);
char		**create_mtx_from_input(t_parsing parsing);


// Built-ins
//void		builtin_pwd(t_builtin	*pBuiltin);
//int			builtin_exit(t_all *pAll);
//void	builtin_env(t_builtin *pBuiltin);

// Lst_input_handling
void		dll_input_addback(t_dll_input **lst, t_dll_input *new);
void		dll_input_addfront(t_dll_input **lst, t_dll_input *new);
void		dll_input_clear(t_dll_input **lst);
t_dll_input	*dll_input_last(t_dll_input *lst);
t_dll_input	*dll_input_new(char *content);
void		dll_input_set_index(t_dll_input **stack);
int			dll_input_size(t_dll_input *lst);

#endif