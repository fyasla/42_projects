/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 12:15:14 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/14 17:57:23 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
void	*content;
struct	s_list *next;
}				t_list;

void	*memset(void *b, int c, size_t len);
void	bzero(void *s, size_t n);
void 	*memcpy(void *dst, const void *src, size_t n);
void 	*memccpy(void *dst, const void *src, int c, size_t n);
void 	*memmove(void *dst, const void *src, size_t len);
void 	*memchr(const void *s, int c, size_t n);
int		memcmp(const void *s1, const void *s2, size_t n);
size_t	strlen(const char *s);
int		isalpha(int c);
int		isdigit(int c);
int		isalnum(int c);
int		isascii(int c);
int		isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*strchr(const char *s, int c);
char	*strrchr(const char *s, int c);
int		strncmp(const char *s1, const char *s2, size_t n);
size_t	strlcpy(char * dst, const char * src, size_t dstsize);
size_t	strlcat(char * dst, const char * src, size_t dstsize);
char	*strnstr(const char *haystack, const char *needle, size_t len);
int		atoi(const char *str);
void	*calloc(size_t count, size_t size);
char	*strdup(const char *s1);
char *ft_substr(char const *s, unsigned int start,
size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);
char *ft_itoa(int n);
char *ft_strmapi(char const *s, char (*f)(unsigned
int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void 	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *));