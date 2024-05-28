NAME = libft.a
CC = cc
INCLUDES = ../includes
CFLAGS = -Wall -Wextra -Werror -g -I$(INCLUDES)
COMPILE = $(CC) $(CFLAGS) -c 
ARCHIVE = ar rc $(NAME)

CHAR_HAND = ./char.handling
CONVERSIONS = ./conversions
PRINTF = ./ft_printf
GET_NEXT_LINE = ./get_next_line
LIST_HAND = ./list.handling
MATRIX_HAND = ./matrix.handling
MEMORY_HAND = ./memory.handling
PRINTS = ./prints
STRING_HAND = ./string.handling


GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m
RESET=\033[0m

SRC = ./char.handling/ft_isalnum.c \
	./char.handling/ft_isalpha.c \
	./char.handling/ft_isascii.c \
	./char.handling/ft_isdigit.c \
	./char.handling/ft_isprint.c \
	./char.handling/ft_tolower.c \
	./char.handling/ft_toupper.c \
	./conversions/ft_atoi.c \
	./conversions/ft_atoi_base.c \
	./conversions/ft_atol.c \
	./conversions/ft_itoa.c \
	./conversions/ft_putnbr_fd.c \
	./ft_printf/ft_printf.c \
	./ft_printf/ft_putaddr.c \
	./ft_printf/ft_putchar.c \
	./ft_printf/ft_putchar_fd.c \
	./ft_printf/ft_putendl_fd.c \
	./ft_printf/ft_putnbr_base.c \
	./ft_printf/ft_putnbr_base_unsigned.c \
	./ft_printf/ft_putnbr_base_unsigned_long.c \
	./ft_printf/ft_putstr.c \
	./ft_printf/ft_putstr_fd.c \
	./ft_printf/ft_specifiers.c \
	./ft_printf/ft_strlen.c \
	./get_next_line/gnl.c \
	./get_next_line/gnl_utils.c \
	./list.handling/dll/dll_add_back.c \
	./list.handling/dll/dll_add_front.c \
	./list.handling/dll/dll_clear.c \
	./list.handling/dll/dll_iterate.c \
	./list.handling/dll/dll_last.c \
	./list.handling/dll/dll_new.c \
	./list.handling/dll/dll_size.c \
	./list.handling/dll/dll_set_index.c \
	./list.handling/dll/finders.c \
	./list.handling/ll/ft_lstadd_back.c \
	./list.handling/ll/ft_lstadd_front.c \
	./list.handling/ll/ft_lstclear.c \
	./list.handling/ll/ft_lstdelone.c \
	./list.handling/ll/ft_lstiter.c \
	./list.handling/ll/ft_lstlast.c \
	./list.handling/ll/ft_lstmap.c \
	./list.handling/ll/ft_lstnew.c \
	./list.handling/ll/ft_lstsize.c \
	./matrix.handling/count_mtx_elements.c \
	./matrix.handling/memory_management.c \
	./matrix.handling/search.c \
	./memory.handling/ft_calloc.c \
	./memory.handling/ft_memchr.c \
	./memory.handling/ft_memcmp.c \
	./memory.handling/ft_memcpy.c \
	./memory.handling/ft_memmove.c \
	./memory.handling/ft_memset.c \
	./string.handling/ft_bzero.c \
	./string.handling/ft_isint.c \
	./string.handling/ft_split.c \
	./string.handling/ft_strchr.c \
	./string.handling/ft_strdup.c \
	./string.handling/ft_striteri.c \
	./string.handling/ft_strjoin.c \
	./string.handling/ft_strlcat.c \
	./string.handling/ft_strlcpy.c \
	./string.handling/ft_strlen.c \
	./string.handling/ft_strmapi.c \
	./string.handling/ft_strncmp.c \
	./string.handling/ft_strnstr.c \
	./string.handling/ft_strrchr.c \
	./string.handling/ft_strtrim.c \
	./string.handling/ft_substr.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)	LIBFT COMPILED! 📖✅ $(RESET)"
	@$(ARCHIVE) $(OBJ)
RM = rm -f

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)	OBJS REMOVED $(RESET)"

fclean: clean
	@$(RM) */**/*.o
	@$(RM) $(NAME)
	@echo "$(RED)	LIBFT DESTROYED! 🗑️ 🔴 $(RESET)"

re: fclean all

# .SILENT:
.PHONY: all clean fclean re