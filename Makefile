# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 09:14:04 by brulutaj          #+#    #+#              #
#    Updated: 2024/10/10 15:53:41 by brulutaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
HEADERS = ./Libft/Headers
INCLUDES = ./includes
CFLAGS = -Wextra -Werror -Wall -I$(HEADERS) -I$(INCLUDES) -g
RM = rm -f

LIBFT_MAKE = ./Libft

SRC =	./main.c \
		./src/builtins/cd.c \
		./src/builtins/echo.c \
		./src/builtins/env.c \
		./src/builtins/exit.c \
		./src/builtins/export.c \
		./src/builtins/pwd.c \
		./src/builtins/unset.c \
		./src/builtins/utils/env_utils.c \
		./src/builtins/utils/export_utils.c \
		./src/builtins/utils/list_utils.c \
		./src/builtins/utils/mtx_from_env.c \
		./src/builtins/utils/free.c \
		./src/exec/exec_utils.c \
		./src/exec/exec.c \
		./src/exec/heredoc.c \
		./src/exec/init_utils.c \
		./src/exec/init.c \
		./src/exec/redirect.c \
		./src/exec/shell_init.c \
		./src/exec/shell_utils.c \
		./src/exec/signals.c \
		./src/parsing/expander/expand_var.c \
		./src/parsing/expander/expander_utils.c \
		./src/parsing/matrix/assign_tokens.c \
		./src/parsing/matrix/mtx_handler.c \
		./src/parsing/matrix/utils/mtx_utils.c \
		./src/parsing/matrix/utils/mtx_utils2.c \
		./src/parsing/matrix/utils/mtx_utils3.c \
		./src/parsing/merger/quote_merger_utils.c \
		./src/parsing/merger/quote_merger.c \
		./src/parsing/parse_struct/parse_struct.c \
		./src/parsing/parse_struct/parse_struct_utils.c \
		./src/parsing/parse_struct/parsing.c \
		./src/parsing/parse_struct/shell_args.c \
		./src/parsing/syntax_error/is_valid_variable.c \
		./src/parsing/syntax_error/syntax_error.c \
		./src/fd_utils.c
#		./waste/write_tokens.c

$(NAME): $(SRC)
	@make all -s -C $(LIBFT_MAKE)
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(HEADERS) $(SRC) -L$(LIBFT_MAKE) -lft -lreadline -o $(NAME)

all: $(NAME)

clean:
	@make clean -s -C $(LIBFT_MAKE)

fclean: clean
	@make fclean -s -C $(LIBFT_MAKE)
	@$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

VALGRIND = valgrind --suppressions=ignore_readline.txt --quiet --leak-check=full --show-leak-kinds=all --track-origins=yes --track-origins=yes

valgrind: all
	clear
	$(VALGRIND) ./$(NAME)

# .SILENT:
.PHONY: all bonus clean fclean re
