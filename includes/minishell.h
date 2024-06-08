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

typedef enum	e_quotes
{
	STAY,
	MERGE_PREV,
	MERGE_NEXT,
	MERGE_BOTH,
}	t_quotes;

typedef enum	e_token
{
	WORDS,
	ARG,
	CMD,
	FILE_W,
	EOF_DEL,
	DOLLAR_SIGN,
	PIPE,
	R_INPUT,
	R_OUTPUT,
	D_RED_INPUT,
	D_RED_OUTPUT,
	D_QUOTE,
	S_QUOTE,
}	t_token;

typedef struct	s_input
{
	char			*content;
	int				token;
	int				merge;
	struct s_input	*next;	
	struct s_input	*prev;
}	t_input;

typedef struct	s_parsing
{
	char	*input;
	char	**mtx_from_input;
	int		*arr_token;
	int		*index_to_merge;
	int		size;
}	t_parsing;

typedef struct	s_builtin
{
	char	*path;

}	t_builtin;

typedef struct	s_all
{
	t_list		*envp;
	t_input		*cmd_line;
	t_builtin	ptr;
}	t_all;

// --- Parsing --- //

// Char_handling
int			check_spaces(char c);
int			handle_quotes(char *s);
int			handle_operators(char *s);
int			handle_not_spaces(char *s);
// Get_all_info
t_all		get_all_info(t_all all_info, char *line, char **envp);
t_list		*create_list_from_envp(char **envp);
t_input		*create_list_from_input(t_parsing parsing);
t_parsing	parse_input(t_parsing parsing);
// Get_arr_token
int			get_word_token(int token);
int			find_token(char *str);
int			first_token_check(t_parsing parsing);
int			*analyse_words_token(t_parsing parsing);
int			*get_arr_token(t_parsing parsing);
// Get_mtx_input
int			count_words(char *s);
int			word_len(char *s);
char		**new_string(char **mtx, char *s);
char		**get_mtx_from_input(t_parsing parsing);
// Quotes_handling
int			find_which_merge_flag(char *input, int i);
t_input		*switch_merge_flag(t_input *cmd_line, int quote_nbr, int which_merge);
t_input		*check_if_need_merge(t_parsing parsing, t_input *cmd_line);


// --- Execution --- //
// Built-ins
//void		builtin_pwd(t_builtin	*pBuiltin);
//int			builtin_exit(t_all *pAll);
//void	builtin_env(t_builtin *pBuiltin);

// Lst_input_handling
void		dll_input_addback(t_input **lst, t_input *new);
void		dll_input_addfront(t_input **lst, t_input *new);
void		dll_input_clear(t_input **lst);
t_input		*dll_input_last(t_input *lst);
t_input		*dll_input_new(char *content);
int			dll_input_size(t_input *lst);

#endif