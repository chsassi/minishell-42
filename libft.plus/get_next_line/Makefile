NAME = libgnl.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCLUDES)
COMPILE = $(CC) $(CFLAGS) -c 
ARCHIVE = ar rc $(NAME)
INCLUDES = ../../includes

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m

SRC =	./gnl.c \
		./gnl_utils.c \

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