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

typedef struct	s_input
{
	char			*content;
	char			**args;
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
}	t_all;

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
// Get_arr_token
int			get_word_token(int token);
int			find_token(char *str);
int			first_token_check(t_parsing parsing);
int			*analyse_words_token(t_parsing parsing);
int			*get_arr_token(t_parsing parsing);
// Get_final_cmd_line
t_input		*create_cmdline_with_cmds(t_input *cmd_line);
char		**create_args_mtx_from_lst(t_input **head);
t_input		*get_args_mtx(t_input *new_cmdline, t_input *cmd_line);
// Get_input_complete
t_input		*get_final_cmd_line(t_input *cmd_line);
t_all		get_final_input(char *line, t_all all_info);
t_all		get_input_complete(t_all all_info, char *line, char **envp);
// Get_mergedcmd_line
char		*get_merged_cmdline(t_input *cmd_line);
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
int			find_merge_flag_quote(char *input, int i);
int			find_merge_flag_dollar_sign(char *input, int i);
int			find_which_merge_flag(char *input, int i, int token);
t_input		*switch_merge_flag(t_input *cmd_line, int token_nbr, int which_merge);
t_input		*handle_merge_flag(char *input, t_input *cmd_line, int token_nbr, int i);
t_input		*check_if_need_merge(t_parsing parsing, t_input *cmd_line);
// Handling_token
int			check_if_operator(int token);
int			count_nbr_args(t_input *tmp);
// Trim_quotes
t_all		handle_trim_quotes(t_all all_info);
char		*trim_quotes(char *content);

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
