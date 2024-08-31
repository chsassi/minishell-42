/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:25:34 by brulutaj          #+#    #+#             */
/*   Updated: 2024/08/29 11:42:39 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "minishell.h"
# include <readline/readline.h>
# include <readline/history.h>

// typedef struct s_all	t_all;

enum e_token
{
	CMD = -1,
	QUOTE = '\'',
	DOUBLE_QUOTE = '\"',
	ENV = '$',
	PIPE_LINE = '|',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	HERE_DOC,
	DREDIR_OUT,
};

enum e_state
{
	IN_DQUOTE,
	IN_QUOTE,
	GENERAL,
};

// Helper functions

int				is_quote(char c);
int				is_special_char(char c);
int				is_normal_letter(char *input, int i);
void			count_normal_token(char *input, int *i, int *token);
int				count_quote_token(char *input, int *i, int *token);
int				count_single_quote_token(char *input, int *i, int *token);
int				count_double_quote_token(char *input, int *i, int *token);
void			count_env_token(char *input, int *i, int *token);
void			count_operator_token(char *input, int *i, int *token);
int				env_token_length(char *input);
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

// typedef struct s_elem
// {
// 	char			*content;
// 	int				len;
// 	int				pipe[2];
// 	enum e_token	type;
// 	enum e_state	state;
// 	struct s_elem	*next;
// 	struct s_elem	*prev;
// }	t_elem;

// typedef struct s_parsing
// {
// 	t_elem			*head;
// 	t_elem			*tail;
// 	int				size;
// }	t_parsing;

// // Token utils

// enum e_token	get_quote_token(char c);
// enum e_token	get_special_token(const char *input, int *index);
// enum e_token	input_red_token(const char *input, int *index);
// enum e_token	output_red_token(const char *input, int *index);
// enum e_token	find_token_type(const char *input, int *index);

// // Process input

// void			process_words(t_parsing *all, char *input, int *index,
// 					enum e_state state);
// void			process_quote(t_parsing *all, char *input, int *index,
// 					enum e_state state);

// // Structure initialization

// t_parsing			*init_all(void);
// t_elem			*create_elem(char *content, int len, enum e_token type);
// void			add_token(t_parsing *all, t_elem *new_elem);

// // Lexer

// const char		*token_to_string(enum e_token token);
// t_parsing			*assign_tokens(char *input);

#endif
