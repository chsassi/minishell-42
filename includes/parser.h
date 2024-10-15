/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:25:34 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/13 17:18:04 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "minishell.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_env	t_env;

enum e_token
{
	WORD = -1,
	QUOTE = '\'',
	DOUBLE_QUOTE = '\"',
	PIPE_LINE = '|',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	HERE_DOC,
	DREDIR_OUT,
};

enum e_merge
{
	NEXT,
	PREV,
	BOTH,
	NO,
};

enum e_state
{
	IN_DQUOTE,
	GENERAL,
};

typedef struct s_env	t_env;
typedef struct s_shell	t_shell;
typedef struct s_pars	t_pars;
typedef struct s_all	t_all;

typedef struct s_pars
{
	char			*str;
	int				type;
	struct s_pars	*next;
	struct s_pars	*prev;
}	t_pars;

typedef struct s_helper
{
	char	*first_str;
	char	*second_str;
	char	*third_str;
	char	*result;
	char	*env_str;
}	t_helper;

typedef struct s_phelp
{
	char	*input_exp;
	char	**mtx;
	int		*tokens;
	t_pars	*parser;
}	t_phelp;

typedef struct s_exp
{
	char			*inp;
	t_env			*env;
	int				*i;
	enum e_state	state;
}	t_exp;

typedef struct s_merge
{
	char	*str;
	char	*trimm;
	char	*tmp;
}	t_merge;

// Helper functions
int				is_quote(char c);
int				is_special_char(char c);
int				is_normal_letter(char *input, int i);
void			count_normal_token(char *input, int *i, int *token);
int				count_quote_token(char *input, int *i, int *token);
int				count_single_quote_token(char *input, int *i, int *token);
int				count_double_quote_token(char *input, int *i, int *token);
void			count_operator_token(char *input, int *i, int *token);
int				operator_token_length(char *input);
int				quote_token_length(char *input);
int				normal_token_length(char *input);

// Matrix functions
int				count_number_of_tokens(char *input);
int				token_length(char *input);
char			**fill_mtx(char **mtx, char *input);
char			**create_mtx(char *input);
int				assign_token(char *str);
int				*token_arr(char **mtx);
int				count_pars(t_pars *p);

//Expansion utils
int				is_escaped_char(int c);
int				check_expansion(char *input, int *i);
char			*process_escaped(char *str, int *i);
char			*create_escaped_str(char *content, int *i);
char			*processed_str_exp(char *content);
char			*expansion(t_all *all, t_env *envp);
char			*heredoc_expansion(t_all *all, char *value);

// Expansion function
char			*find_env_string(char *input, t_env *envp, int len);
char			*env_string(t_all *all, char *input, int *i, t_env *envp);
void			free_trash(t_phelp *ptr);
t_shell			*parsing(t_all *pAll);
char			*exp_string(t_all *all, t_exp p);
void			set_state(enum e_state *state);

// Quote Trimming
int				type_of_merge(char *str, int start, int end);
int				*array_of_merges(char *input, char **mtx);
int				*process_arr_merger(char *input, char **mtx);
char			*trimm_quotes(char *str);
char			*merge_string(int *arr, char **mtx, int *i);

// Parse struct
int				quot_tok_len(char *input);
t_pars			*new_parse_node(char **mtx, int *i, int tok, int *arr);
t_pars			*last_parse(t_pars *lst);
void			add_back_parse(t_pars **lst, t_pars *new);
void			free_parse_node(t_pars *parser);
void			clear_parse(t_pars *parser);
t_pars			*parse_struct_init(char *input, char **mtx, int *token);
char			*joined_merger(char *str1, char *str2, int flag);
char			**red_mtx(t_pars **parser);
t_pars			*reorg_struct(t_pars *curr_redirect, char **mtx, int *i);
int				len_red_mtx(t_pars *parser);
int				is_redirect(int type);
char			**cmd_mtx(t_pars *parser);

// Syntax
int				check_redir_error(t_pars *parser);
int				check_pipe_error(t_pars *parser);
int				check_all_errors(t_pars *parser);

#endif
