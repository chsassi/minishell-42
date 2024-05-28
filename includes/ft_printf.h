/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:56:13 by chsassi           #+#    #+#             */
/*   Updated: 2023/11/18 18:56:14 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

# define BASE16 "0123456789abcdef"
# define BASE16UPPER "0123456789ABCDEF"
# define BASE10 "0123456789"

/**
 * @brief Prints formatted output to stdout.
 * @param str The format string.
 * @param ... Additional arguments.
 * @return The number of characters printed.
 */
int		ft_printf(const char *str, ...);

/**
 * @brief Prints the address of a pointer to stdout.
 * @param ptr The pointer whose address is to be printed.
 * @param length Pointer to the length counter.
 */
void	ft_putaddr(void *ptr, int *length);

/**
 * @brief Prints a character to stdout.
 * @param c The character to be printed.
 * @param length Pointer to the length counter.
 */
void	ft_putchar(char c, int *length);

/**
 * @brief Prints an unsigned long number in the specified base to stdout.
 * @param nbr The unsigned long number to be printed.
 * @param base The base to be used for printing.
 * @param length Pointer to the length counter.
 */
void	ft_putnbr_base_unsigned_long(unsigned long nbr,
			char *base, int *length);

/**
 * @brief Prints an unsigned number in the specified base to stdout.
 * @param nbr The unsigned number to be printed.
 * @param base The base to be used for printing.
 * @param length Pointer to the length counter.
 */
void	ft_putnbr_base_unsigned(unsigned int nbr, char *base, int *length);

/**
 * @brief Prints a number in the specified base to stdout.
 * @param nbr The number to be printed.
 * @param base The base to be used for printing.
 * @param length Pointer to the length counter.
 */
void	ft_putnbr_base(long nbr, char *base, int *length);

/**
 * @brief Prints a string to stdout.
 * @param str The string to be printed.
 * @param length Pointer to the length counter.
 */
void	ft_putstr(char *str, int *length);

/**
 * @brief Calculates the length of a string.
 * @param str The string.
 * @return The length of the string.
 */
int		xstrlen(char *str);

/**
 * @brief Handles the conversion specifiers in the format string.
 * @param c The conversion specifier character.
 * @param ap The va_list containing the additional arguments.
 * @param length Pointer to the length counter.
 */
void	ft_specifiers(char c, va_list ap, int *length);

#endif
