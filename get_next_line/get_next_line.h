/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 09:56:28 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/03 15:41:19 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
int		ft_pos(char c, char *str);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(char *ptr, unsigned int n);
char	*ft_substr(char *str, int start, int size);
int		get_next_line(int fd, char **line);

#endif
