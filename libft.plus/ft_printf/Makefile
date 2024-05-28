NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCLUDES)
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rc $(NAME)
INCLUDES = ../../includes

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m

SRC =	./ft_printf.c \
		./ft_putchar.c \
		./ft_putstr.c \
		./ft_putnbr_base.c \
		./ft_putnbr_base_unsigned.c \
		./ft_putnbr_base_unsigned_long.c \
		./ft_putaddr.c \
		./ft_strlen.c \
		./ft_specifiers.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(COMPILE) $(CFLAGS) -c $(SRC)
		@ar rc $(NAME) $(OBJ)

RM = rm -f

clean:
		@$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean rm