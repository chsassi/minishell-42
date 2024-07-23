# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 09:14:04 by brulutaj          #+#    #+#              #
#    Updated: 2024/07/15 15:54:43 by brulutaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
HEADERS = ./Libft/Headers
INCLUDES = ./includes
CFLAGS = -Wextra -Werror -Wall -g -I$(HEADERS) -I$(INCLUDES)
RM = rm -f

LIBFT_MAKE = ./Libft

SRC =	./main.c \
		./src/builtins/pwd.c \
		./src/exec/signals.c \
		./src/parsing/lexer_utils.c \
		./src/parsing/lexer.c \
		./src/parsing/process_input.c \
		./src/parsing/struct_init.c \
		./src/parsing/token_utils.c \

all: $(NAME)

$(NAME): $(SRC)
	@make all -s -C $(LIBFT_MAKE)
	$(CC) $(FLAGS) -I$(INCLUDES) -I$(HEADERS) $(SRC) -L$(LIBFT_MAKE) -lft -lreadline -o $(NAME)

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