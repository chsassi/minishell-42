/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:46:24 by chsassi           #+#    #+#             */
/*   Updated: 2023/12/04 16:46:25 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

/**
 * @brief Reads a line from a file descriptor and returns it as a string.
 * @param fd The file descriptor to read from.
 * @return A pointer to the line read from the file descriptor, or NULL if an error occurred or the end of file was reached.
 */
char	*gnl(int fd);

/**
 * @brief Returns the length of the input string.
 * @param str a pointer to a null-terminated string.
 * @return the length of the string str.
 */
int		strlen_gnl(char *str);

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory.
 * The memory is set to zero.
 * @param nmemb the number of elements to create.
 * @param size the size of each element.
 * @return a pointer to the created array. NULL if the allocation failed.
 */
void	*calloc_gnl(size_t nmemb, size_t size);

/**
 * @brief Concatenates two strings and returns the result as a new string.
 * @param s1 The first string.
 * @param s2 The second string.
 * @return A pointer to the concatenated string, or NULL if the allocation failed.
 */
char	*strjoin_gnl(char **s1, char *s2);

/**
 * @brief Searches for the first occurrence of the character c in the string s.
 * @param s The string to search in.
 * @param c The character to search for.
 * @return A pointer to the first occurrence of the character c in the string s, or NULL if the character is not found.
 */
int		strchr_gnl(char *s, int c);

/**
 * @brief Extracts a substring from the input string.
 * @param s The input string.
 * @param start The starting index of the substring.
 * @param end The ending index of the substring.
 * @return A pointer to the extracted substring, or NULL if the allocation failed or the indices are out of range.
 */
char	*substr_gnl(char *s, size_t start, size_t end);

#endif