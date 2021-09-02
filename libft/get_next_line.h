/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:28:48 by fbougama          #+#    #+#             */
/*   Updated: 2021/09/02 18:17:09 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
# endif

size_t	ft_sl(char const *str);
char	*ft_substr2(char const *str, size_t start, size_t len);
char	*ft_bzero2(char *ptr, size_t len);
char	*ft_strmove2(char const *s1);
char	*ft_strjoin2(char const *s1, char const *s2);
int		ft_p(char *str);
int		ft_free(char **line, char **buffer);
int		get_next_line(int fd, char **line);
void	rd_buff(char **buff, int *rd, int fd);

#endif
