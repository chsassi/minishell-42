/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:51:46 by brulutaj          #+#    #+#             */
/*   Updated: 2024/08/21 11:16:24 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <sys/stat.h>

typedef struct s_env	t_env;

typedef struct s_dll
{
	int				value;
	int				index;
	struct s_dll	*prev;
	struct s_dll	*next;
}	t_dll;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_env	t_env;

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		len_cmp(char *s1, char *s2);
int		ft_colen(char **mtx);
int		ft_rowlen(char **mtx);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		ft_lstsize(t_list *lst);
int		dll_size(t_dll *lst);
int		find_min_index(t_dll *pStack);
int		find_min_value(t_dll *pStack);
int		find_max_index(t_dll *pStack);
int		find_max_value(t_dll *pStack);
void	ft_bzero(char *s, size_t n);
int		ft_strlen_until(char *str, char c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char c);
char	**split_into_mtx(char *str);
char	**copy_mtx(char **mtx);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_line(int fd);
void	write_mtx(char **mtx);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	free_mtx(char **mtx);
void	dll_add_back(t_dll **lst, t_dll *new);
void	dll_add_front(t_dll **lst, t_dll *new);
void	dll_clear(t_dll **lst);
void	set_index(t_dll **stack);
void	env_lstadd_back(t_env **head, t_env *new);
t_dll	*dll_iterate(t_dll *lst);
t_dll	*dll_last(t_dll *lst);
t_dll	*dll_new(int value);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*gnl(int fd);
size_t	ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(char *str, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_putchar_printf(int c);
int		ft_putstr_printf(char *str);
int		ft_putnbr_printf(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_putaddr(uintptr_t ptr);
int		ft_puthex(unsigned int n, const char type);
int		ft_printf(const char *str, ...);
void	free_env_var(char *var, char *content);
void	free_env_node(t_env *node);
void	free_env_list(t_env *head);


#endif
