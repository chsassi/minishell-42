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
		./src/free_exit_handling/free_parsing.c \
		./src/lst_input_handling/dll_input_addback.c \
		./src/lst_input_handling/dll_input_addfront.c \
		./src/lst_input_handling/dll_input_clear.c \
		./src/lst_input_handling/dll_input_last.c \
		./src/lst_input_handling/dll_input_new.c \
		./src/lst_input_handling/dll_input_size.c \
		./src/parsing/expansion/expand_with_quotes.c \
		./src/parsing/expansion/expand.c \
		./src/parsing/expansion/get_env.c \
		./src/parsing/expansion/handling_env.c \
		./src/parsing/get_info/get_all_info.c \
		./src/parsing/get_info/get_arr_token.c \
		./src/parsing/get_info/get_final_cmd_line.c \
		./src/parsing/get_info/get_input_complete.c \
		./src/parsing/get_info/get_merged_cmdline.c \
		./src/parsing/get_info/get_mtx_input.c \
		./src/parsing/handlers/handling_char.c \
		./src/parsing/handlers/handling_merge_flag.c \
		./src/parsing/handlers/handling_token.c \
		./src/parsing/handlers/trim_quotes.c

all: $(NAME)

libft:
	make all -C $(LIBFT_DIR)

$(NAME): libft $(SRC)
	$(CC) $(CFLAGS) -I. -I$(INCLUDES) $(SRC) -L$(LIBFT_DIR) -lft -lreadline -o $(NAME)
	@echo "$(BLUE)	MINISHELL COMPILED!$(RESET)"

RM = rm -f

valgrind: $(NAME)
	valgrind --leak-check=full --show-reachable=yes --suppressions=readline.supp ./$(NAME)

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all