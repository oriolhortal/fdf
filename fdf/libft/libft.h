/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:42:16 by ohortal-          #+#    #+#             */
/*   Updated: 2023/10/03 11:42:01 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_lstsize(t_list *lst);
int				ft_atoi(const char *str);
int				ft_strlen(const char *s);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
void			ft_bzero(void *s, size_t n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memset(void *str, int c, size_t n);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_itoa(int n);
char			*ft_strdup(const char *s);
char			*ft_strchr(const char *s, int c);
char			**ft_split(char const *s, char c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *));
char			*read_line(int fd, char *storage);
char			*first_line(char *storage);
char			*delete_first_line(char *storage);
char			*get_next_line(int fd);
int				my_strlen(char *str);
char			*my_strchr(const char *str, int c);
char			*my_strjoin(char *buffer, char *tail, ssize_t size);
void			*true_free(char **buffer);
void			*my_calloc(size_t count, size_t size);

#endif
