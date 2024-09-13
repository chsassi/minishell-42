# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 14:05:40 by brulutaj          #+#    #+#              #
#    Updated: 2024/09/13 18:45:13 by brulutaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a
CC				= cc
HEADERS			= ./Headers
CFLAGS			= -Wall -Wextra -Werror -I$(HEADERS) -g
COMPILE			= $(CC) $(CFLAGS) -c
ARCHIVE			= ar rc $(NAME)

SRCS			= ./Booleans/ft_isalnum.c 			\
					./Booleans/ft_isalpha.c 		\
					./Booleans/ft_isascii.c 		\
					./Booleans/ft_isdigit.c 		\
					./Booleans/ft_isprint.c 		\
					./Booleans/len_cmp.c 			\
					./Strings_ft/ft_atoi.c 			\
					./Strings_ft/ft_atol.c			\
					./Strings_ft/ft_bzero.c 		\
					./Strings_ft/ft_memchr.c 		\
					./Strings_ft/ft_memcmp.c 		\
					./Strings_ft/ft_memcpy.c 		\
					./Strings_ft/ft_memmove.c 		\
					./Strings_ft/ft_memset.c 		\
					./Strings_ft/ft_strchr.c 		\
					./Strings_ft/ft_striteri.c 		\
					./Strings_ft/ft_strlcat.c 		\
					./Strings_ft/ft_strlcpy.c 		\
					./Strings_ft/ft_strlen.c 		\
					./Strings_ft/ft_strncmp.c 		\
					./Strings_ft/ft_strcmp.c 		\
					./Strings_ft/ft_strnstr.c 		\
					./Strings_ft/ft_strrchr.c 		\
					./Strings_ft/ft_tolower.c 		\
					./Strings_ft/ft_toupper.c 		\
					./Mem_alloc/ft_calloc.c 		\
					./Mem_alloc/ft_itoa.c 			\
					./Mem_alloc/ft_split.c 			\
					./Mem_alloc/ft_strdup.c 		\
					./Mem_alloc/ft_strjoin.c 		\
					./Mem_alloc/ft_strmapi.c 		\
					./Mem_alloc/ft_strtrim.c 		\
					./Mem_alloc/ft_substr.c 		\
					./Mem_alloc/ft_line.c 			\
					./Mtx_ft/free_mtx.c 			\
					./Mtx_ft/split_into_mtx.c 		\
					./Mtx_ft/ft_colen.c 			\
					./Mtx_ft/ft_rowlen.c 			\
					./Mtx_ft/copy_mtx.c				\
					./Mtx_ft/write_mtx.c			\
					./Put_ft/ft_putchar_fd.c 		\
					./Put_ft/ft_putendl_fd.c 		\
					./Put_ft/ft_putnbr_fd.c 		\
					./Put_ft/ft_putstr_fd.c 		\
					./List_ft/ft_lstadd_back.c 		\
					./List_ft/ft_lstadd_front.c 	\
					./List_ft/ft_lstclear.c 		\
					./List_ft/ft_lstdelone.c 		\
					./List_ft/ft_lstiter.c 			\
					./List_ft/ft_lstlast.c 			\
					./List_ft/ft_lstmap.c 			\
					./List_ft/ft_lstnew.c 			\
					./List_ft/ft_lstsize.c 			\
					./List_ft/env_list_helpers.c 	\
					./Double_list/dll_add_back.c	\
					./Double_list/dll_add_front.c	\
					./Double_list/dll_clear.c		\
					./Double_list/dll_iterate.c		\
					./Double_list/dll_last.c		\
					./Double_list/dll_new.c			\
					./Double_list/dll_set_index.c	\
					./Double_list/dll_size.c		\
					./Double_list/finders.c			\
					./Get_Next_Line/gnl_utils.c 	\
					./Get_Next_Line/gnl.c 			\
					./Printf/ft_printf.c 			\
					./Printf/ft_putaddr.c 			\
					./Printf/ft_putchar_printf.c 	\
					./Printf/ft_puthex.c 			\
					./Printf/ft_putnbr_printf.c 	\
					./Printf/ft_putnbr_u.c 			\
					./Printf/ft_putstr_printf.c

OBJS			= $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(ARCHIVE) $(OBJS)

RM				= rm -f
clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) */**/*.o
				@$(RM) $(NAME)

re:				fclean all
