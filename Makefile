# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 09:14:04 by brulutaj          #+#    #+#              #
#    Updated: 2024/09/24 07:53:29 by brulutaj         ###   ########.fr        #
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
		./src/utils/list_utils.c \
		./src/builtins/env.c 	\
		./src/parsing/utils/mtx_utils3.c \
		./src/parsing/utils/mtx_utils.c \
		./src/parsing/utils/mtx_utils2.c \
		./src/builtins/unset.c \
		./src/builtins/pwd.c \
		./src/builtins/cd.c \
		./src/exec/heredoc.c \
		./src/exec/signals.c \
		# ./src/builtins/exit.c \
		# ./src/parsing/mtx_handler.c \
		# ./src/parsing/assign_tokens.c \
		# ./src/parsing/mtx_handler.c \
		# ./src/exec/exec.c \
		# ./src/builtins/export.c \

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

VALGRIND = valgrind --suppressions=ignore_readline.txt --leak-check=full --show-leak-kinds=all --track-origins=yes -s

valgrind: all
	$(VALGRIND) ./$(NAME)

# .SILENT:
.PHONY: all bonus clean fclean re