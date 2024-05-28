NAME = minishell

CC = cc
INCLUDES = ./includes
CFLAGS = -Wextra -Werror -Wall -g -I$(INCLUDES)
COMPILE = $(CC) $(CFLAGS) -c


LIBFT_DIR = ./libft.plus

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m
RESET=\033[0m

SRC =	./src/main.c \
		./src/builtins/echo.c \
		./src/builtins/env.c \
		./src/builtins/exit.c \
		./src/builtins/export.c \
		./src/builtins/pwd.c \
		./src/builtins/unset.c \
		./src/lst_input_handling/dll_input_addback.c \
		./src/lst_input_handling/dll_input_addfront.c \
		./src/lst_input_handling/dll_input_clear.c \
		./src/lst_input_handling/dll_input_last.c \
		./src/lst_input_handling/dll_input_new.c \
		./src/lst_input_handling/dll_input_set_index.c \
		./src/lst_input_handling/dll_input_size.c \
		./src/parsing/parsing.c \
		./src/parsing/parser_utils.c

all: $(NAME)

libft:
	make all -C $(LIBFT_DIR)

$(NAME): libft $(SRC)
	$(CC) $(CFLAGS) -I. -I$(INCLUDES) $(SRC) -L$(LIBFT_DIR) -lft -lreadline -o $(NAME)

	@echo "$(BLUE)	MINISHELL COMPILED!$(RESET)"

RM = rm -f

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all