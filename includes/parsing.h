#ifndef PARSING_H
# define PARSING_H

# include "libft.h"

typedef struct	s_all	t_all;

typedef struct	s_input t_input;

typedef enum	e_quotes
{
	STAY,
	MERGE_PREV,
	MERGE_NEXT,
	MERGE_BOTH,
}	t_quotes;

typedef enum	e_token
{
	VOID,
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
	OPERATORS,
}	t_token;

typedef struct	s_parsing
{
	char	*input;
	char	**mtx_from_input;
	int		*arr_token;
	int		size;
}	t_parsing;

// --- Parsing --- //

// -Expansion- //
//Expand_with_quotes
int			check_dollar_sign(char *str);
void    	new_content_copy(char *new_content, char *content, char *env, int len);
char		*get_content_with_quotes(char *content, char *env);
//Expand
void		*expand_env(char *content, t_all all_info);
void		*expand_env_with_quotes(char *content, t_all all_info);
t_all		expand_dollar_sign(t_all all_info);
//Get_env
char		*get_expansion(t_list *envp, char *name_env);
char		*get_name_env(char *str);
char		*get_env(char *str, t_all all_info);
//Handling_env
int			find_len_env(t_list *envp, char *name_env);
char		*find_expansion_env(t_list *envp, char *name_env);

// Get_all_info
t_parsing	parse_input(t_parsing parsing);
t_input		*create_list_from_input(t_parsing parsing);
t_list		*create_list_from_envp(char **envp);
t_all		get_all_info(t_all all_info, char *line, char **envp);
// Get_args_mtx
char		**get_args(int *arr_token, char **mtx_cmdline, int index, char **args);
char		**create_args_mtx(int *arr_token, char **mtx_cmdline, int *index);
t_input		*get_args_mtx(t_input *cmd_line);
// Get_arr_token
int			get_word_token(int token);
int			find_token(char *str);
int			first_token_check(int *arr_token, int size);
int			*analyse_words_token(int *arr_token, int size);
int			*get_arr_token(char **mtx, int size);
// Get_input_complete
t_all		get_final_input(char *line, t_all all_info);
t_all		get_input_complete(t_all all_info, char *line, char **envp);
// Get_merged_line
int			*get_merge_arr(t_input *cmd_line, int *merge_arr, int size);
int			*organize_merge_arr(int *merge_arr, int size);
char		*handle_merge_next(char	**mtx_cmdline, int *merge_arr, int *index);
char		*get_new_input(char	**mtx_cmdline, int *merge_arr, int size);
char		*get_merged_line(t_input *cmd_line, int *merge_arr);
// Get_mtx_input
int			count_words(char *s);
int			word_len(char *s);
char		**new_string(char **mtx, char *s);
char		**get_mtx_from_input(t_parsing parsing);

// Handling_char
int			check_spaces(char c);
int			handle_quotes(char *s);
int			handle_operators(char *s);
int			handle_not_spaces(char *s);
int			get_len_word(char *str, int	index);
int			get_index_special_char(char *str, char c);
// Handling_merge_flag
int			check_if_merge_flags_on(t_input *cmdline);
int			find_merge_flag_quote(char *input, int i);
int			find_merge_flag_dollar_sign(char *input, int i);
int			find_which_merge_flag(char *input, int i, int token);
t_input		*switch_merge_flag(t_input *cmd_line, int token_nbr, int which_merge);
t_input		*handle_merge_flag(char *input, t_input *cmd_line, int token_nbr, int i);
t_input		*check_if_need_merge(t_parsing parsing, t_input *cmd_line);
// Handling_mtx_and_lists
char    	**parsing_list_in_mtx(t_input *cmd_line);
// Handling_quotes_as_word_token
t_all		assign_quote_as_words_token(t_all all_info);
// Handling_token
int			check_if_operator(int token);
int			count_rows_args(char **mtx_cmdline, int *arr_token);
// Trim_quotes
char		*trim_quotes(char *content);
t_all		handle_trim_quotes(t_all all_info);

#endif