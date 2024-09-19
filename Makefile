# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 09:14:04 by brulutaj          #+#    #+#              #
#    Updated: 2024/09/13 18:51:16 by brulutaj         ###   ########.fr        #
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
		./src/builtins/env.c \
		./src/utils/list_utils.c \
		./src/exec/exec.c \
		./src/exec/signals.c \
<<<<<<< HEAD
=======
		./src/builtins/cd.c \
		./src/builtins/pwd.c \
		./src/builtins/export.c \
>>>>>>> fbb75f5b0f4482de4c8334639747f254120473b0
		./src/builtins/exit.c \
		./src/utils/list_utils.c \
		./src/utils/free.c \
		./src/builtins/unset.c \
<<<<<<< HEAD
		# ./src/builtins/export.c \
=======
		./src/utils/free.c \
>>>>>>> fbb75f5b0f4482de4c8334639747f254120473b0
		# ./src/parsing/mtx_handler.c \
		# ./src/parsing/assign_tokens.c \
		# ./src/parsing/expander/expand_var.c \
		# ./src/parsing/utils/mtx_utils2.c \
		# ./src/parsing/utils/mtx_utils3.c \
		# ./src/parsing/utils/mtx_utils.c \
		# ./src/parsing/assign_tokens.c \
		# ./src/parsing/mtx_handler.c \
		# ./src/exec/exec.c \
		# ./src/exec/signals.c \
		# ./src/builtins/export.c \
		# ./src/builtins/exit.c \
		# ./src/builtins/unset.c \
		# ./src/free.c \

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