/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:28:48 by fbougama          #+#    #+#             */
/*   Updated: 2020/03/12 17:59:04 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 42

size_t	ft_sl(char const *str);
char	*ft_substr(char const *str, size_t start, size_t len);
char	*ft_bzero(char *ptr, size_t len);
char	*ft_strmove(char const *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_p(char *str);
int		ft_free(char **line, char **buffer);
int		get_next_line(int fd, char **line);

#endif
