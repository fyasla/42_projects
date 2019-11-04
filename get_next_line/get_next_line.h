/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:39:50 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/30 12:00:49 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strclen(const char *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strcdup(const char *s1, const char c);
int		ft_is_in(const char c, const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);
char	*ft_after_first(char *str, char c);
size_t	ft_strlen(const char *str);
void	*ft_bzero(void *b, size_t len);

#endif