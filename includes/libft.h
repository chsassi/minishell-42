/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <chsassi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:42:47 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:33:54 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf.h"
# include "gnl.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <fcntl.h>
# include <strings.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_dll
{
	int				value;
	int				index;
	struct s_dll	*prev;
	struct s_dll	*next;
}	t_dll;


/* CHAR HANDLING */

/**
 * @brief Checks if the given character is an alphanumeric character.
 * @param c an integer representing a character.
 * @return 1 if c is an alphanumeric character, otherwise returns 0.
 */
int		ft_isalnum(int c);

/**
 * @brief Checks if the given character is an alphabetic character (a-z or A-Z).
 * @param c an integer representing a character.
 * @return 1 if c is an alphabetic character (a-z or A-Z), otherwise returns 0.
 */
int		ft_isalpha(int c);

/**
 * @brief Checks if the given character is a valid ASCII character.
 * @param c an integer representing a character.
 * @return 1 if c is a valid ASCII character, otherwise returns 0.
 */
int		ft_isascii(int c);

/**
 * @brief Checks if the given character is a digit (0-9).
 * @param c an integer representing a digit.
 * @return 1 if c is a digit (0-9), otherwise returns 0.
 */
int		ft_isdigit(int c);

/**
 * @brief Checks if the given character is a printable character.
 * @param c an integer representing a character.
 * @return 1 if c is a printable character, otherwise returns 0.
 */
int		ft_isprint(int c);

/**
 * @brief Outputs a character to the specified file descriptor.
 * @param c the character to be output.
 * @param fd the file descriptor.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs a string followed by a newline character to the specified file descriptor.
 * @param s a pointer to the string to be output.
 * @param fd the file descriptor.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Converts a lowercase letter to uppercase.
 * @param c an integer representing a character.
 * @return the uppercase equivalent of c, if c is a lowercase letter, otherwise returns c.
 */
int		ft_toupper(int c);

/**
 * @brief Converts an uppercase letter to lowercase.
 * @param c an integer representing a character.
 * @return the lowercase equivalent of c, if c is an uppercase letter, otherwise returns c.
 */
int		ft_tolower(int c);

/* CONVERSIONS */

/**
 * @brief Converts a string to a long.
 * @param str a pointer to the string to be converted.
 * @return the converted long value.
 */
long	ft_atol(const char *str);

/**
 * @brief Converts a string to an integer.
 * @param str a pointer to the string to be converted.
 * @return the converted integer value.
 */
int		ft_atoi(const char *str);

/**
 * @brief Converts a string to an integer in any base.
 * @param str a pointer to the string to be converted.
 * @return the converted integer value.
 */
int		ft_atoi_base(char *str, char *base);

/**
 * @brief Converts an integer to a string.
 * @param nb the integer to be converted.
 * @return a pointer to the converted string. NULL if the allocation failed.
 */
char	*ft_itoa(int nb);

/**
 * @brief Outputs an integer to the specified file descriptor.
 * @param n the integer to be output.
 * @param fd the file descriptor.
 */
void	ft_putnbr_fd(int n, int fd);

/* LIST HANDLING */

// Linked Lists

/**
 * @brief Adds an element to the end of a linked list.
 * @param lst a pointer to the pointer to the first element of the list.
 * @param new a pointer to the element to be added.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Adds an element to the beginning of a linked list.
 * @param lst a pointer to the pointer to the first element of the list.
 * @param new a pointer to the element to be added.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Deletes all elements of a linked list.
 * @param lst a pointer to the pointer to the first element of the list.
 * @param del a pointer to the function used to delete the content of an element.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Deletes an element from a linked list.
 * @param lst a pointer to the element to be deleted.
 * @param del a pointer to the function used to delete the content of the element.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Applies a function to all elements of a linked list.
 * @param lst a pointer to the first element of the list.
 * @param f a pointer to the function to be applied.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Returns the last element of a linked list.
 * @param lst a pointer to the first element of the list.
 * @return a pointer to the last element of the list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Creates a new list resulting from the application of a function to all elements of a linked list.
 * @param lst a pointer to the first element of the list.
 * @param f a pointer to the function to be applied.
 * @param del a pointer to the function used to delete the content of an element.
 * @return a pointer to the new list. NULL if the allocation failed.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Creates a new element for a linked list.
 * @param content the content of the element.
 * @return a pointer to the new element.
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Counts the number of elements in a linked list.
 * @param lst a pointer to the first element of the list.
 * @return the number of elements in the list.
 */
int		ft_lstsize(t_list *lst);

// Double Linked Lists

/**
 * @brief Adds an element to the end of a double linked list.
 * @param lst a pointer to the pointer to the first element of the list.
 * @param new a pointer to the element to be added.
 */
void	dll_add_back(t_dll **lst, t_dll *new);

/**
 * @brief Adds an element to the beginning of a double linked list.
 * @param lst a pointer to the pointer to the first element of the list.
 * @param new a pointer to the element to be added.
 */
void	dll_add_front(t_dll **lst, t_dll *new);


t_dll	*dll_iterate(t_dll *lst);


t_dll	*dll_last(t_dll *lst);


void	dll_clear(t_dll **lst);


t_dll	*dll_new(int value);


int		dll_size(t_dll *lst);


int		find_min_index(t_dll *pStack);


int		find_min_value(t_dll *pStack);


int		find_max_index(t_dll *pStack);


int		find_max_value(t_dll *pStack);


void	set_index(t_dll **list);

/* MATRIX HANDLING */

/**
 * @brief Copies a matrix.
 * @param mtx matrix.
 * @return matrix copy.
 */
char	**copy_mtx(char **mtx);

/**
 * @brief Calculates cols in a matrix.
 * @param mtx matrix.
 * @return matrix cols.
 */
int		count_cols(char **mtx);

/**
 * @brief Counts an element (char) inside a matrix.
 * @param mtx matrix.
 * @param c the char to count.
 * @return a pointer to the created array. NULL if the allocation failed.
 */
int		count_elements(char **mtx, char c);

/**
 * @brief Calculates rows in a matrix.
 * @param mtx matrix.
 * @return matrix rows.
 */
int		count_rows(char **mtx);

/**
 * @brief Frees a matrix.
 * @param mtx matrix.
 */
void	free_mtx(char **mtx);

/**
 * @brief Allocates a matrix.
 * @param mtx matrix.
 * @param rows mtx rows.
 * @param cols mtx cols.
 */
char	**mtx_alloc(int rows, int cols);

/**
 * @brief Populates an entire matrix with 'X' - useful for floodfill.
 * @param mtx matrix.
 * @param rows mtx rows.
 * @param cols mtx cols.
 */
void	reset_matrix_to_x(char **mtx, int cols, int rows);

/* MEMORY MANAGEMENT */

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory.
 * The memory is set to zero.
 * @param nmemb the number of elements to create.
 * @param size the size of each element.
 * @return a pointer to the created array. NULL if the allocation failed.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Locates the first occurrence of a character in a block of memory.
 * @param s a pointer to the block of memory to be searched.
 * @param c the character to be located.
 * @param n the number of bytes to be searched.
 * @return a pointer to the located character, or NULL if the character does not appear in the block of memory.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares two blocks of memory.
 * @param ptr1 a pointer to the first block of memory.
 * @param ptr2 a pointer to the second block of memory.
 * @param n the number of bytes to be compared.
 * @return an integer less than, equal to, or greater than zero if the first block of memory is found, respectively, to be less than, to match, or be greater than the second block of memory.
 */
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * @param dest a pointer to the destination memory area.
 * @param src a pointer to the source memory area.
 * @param n the number of bytes to be copied.
 * @return a pointer to the destination memory area.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest, even if they overlap.
 * @param dest a pointer to the destination memory area.
 * @param src a pointer to the source memory area.
 * @param n the number of bytes to be copied.
 * @return a pointer to the destination memory area.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Fills the memory with a constant byte.
 * @param s a pointer to the memory area.
 * @param c the value to be set.
 * @param len the number of bytes to be set.
 * @return a pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t len);

/* STRING HANDLING */

/**
 * @brief Fills the memory with zero bytes.
 * @param s a pointer to the memory area.
 * @param n the number of bytes to be set to zero.
 */
void	ft_bzero(void *s, size_t n);


int		ft_isint(char *str);

/**
 * @brief Outputs a string to the specified file descriptor.
 * @param s a pointer to the string to be output.
 * @param fd the file descriptor.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Splits a string into an array of substrings based on a delimiter character.
 * @param str a pointer to the string to be split.
 * @param c the delimiter character.
 * @return a pointer to the array of substrings. NULL if the allocation failed.
 */
char	**ft_split(const char *str, char c);

/**
 * @brief Locates the first occurrence of a character in a string.
 * @param s a pointer to the string to be searched.
 * @param c the character to be located.
 * @return a pointer to the located character, or NULL if the character does not appear in the string.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Duplicates a string.
 * @param s1 a pointer to the string to be duplicated.
 * @return a pointer to the duplicated string. NULL if the allocation failed.
 */
char	*ft_strdup(const char *s1);

/**
 * @brief Applies a function to each character of a string, providing its index as first argument.
 * @param s a pointer to the string.
 * @param f a pointer to the function to be applied.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Concatenates two strings.
 * @param s1 a pointer to the first string.
 * @param s2 a pointer to the second string.
 * @return a pointer to the concatenated string. NULL if the allocation failed.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Appends the NUL-terminated string src to the end of dst.
 * @param dst a pointer to the destination string.
 * @param src a pointer to the source string.
 * @param size the size of the destination buffer.
 * @return the total length of the string they tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Copies up to size - 1 characters from the NUL-terminated string src to dst.
 * @param dst a pointer to the destination string.
 * @param src a pointer to the source string.
 * @param size the size of the destination buffer.
 * @return the total length of the string they tried to create.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Returns the length of the input string.
 * @param str a pointer to a null-terminated string.
 * @return the length of the string str.
 */
size_t	ft_strlen(const char *str);

/**
 * @brief Applies a function to each character of a string.
 * @param s a pointer to the string.
 * @param f a pointer to the function to be applied.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Compares two strings.
 * @param s1 a pointer to the first string.
 * @param s2 a pointer to the second string.
 * @param n the maximum number of characters to compare.
 * @return an integer less than, equal to, or greater than zero if s1 is found, respectively, to be less than, to match, or be greater than s2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locates the first occurrence of a substring in a string.
 * @param big a pointer to the string to be searched.
 * @param little a pointer to the substring to be located.
 * @param len the maximum number of characters to search.
 * @return a pointer to the located substring, or NULL if the substring does not appear in the string.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Locates the last occurrence of a character in a string.
 * @param s a pointer to the string to be searched.
 * @param c the character to be located.
 * @return a pointer to the located character, or NULL if the character does not appear in the string.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Trims the specified characters from the beginning and end of a string.
 * @param s1 a pointer to the string to be trimmed.
 * @param set a pointer to the set of characters to be trimmed.
 * @return a pointer to the trimmed string. NULL if the allocation failed.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Extracts a substring from a string.
 * @param s a pointer to the string.
 * @param start the starting index of the substring.
 * @param len the length of the substring.
 * @return a pointer to the extracted substring. NULL if the allocation failed.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
