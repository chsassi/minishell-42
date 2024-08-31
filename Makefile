# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 09:14:04 by brulutaj          #+#    #+#              #
#    Updated: 2024/08/31 15:55:46 by brulutaj         ###   ########.fr        #
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
		./src/parsing/mtx_handler.c \
		./src/parsing/utils/mtx_utils.c \
		./src/parsing/utils/mtx_utils2.c \
		./src/parsing/utils/mtx_utils3.c \

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