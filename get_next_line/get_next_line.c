/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:39:44 by fbougama          #+#    #+#             */
/*   Updated: 2019/11/26 12:34:34 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*save;
	int			rd;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return(-1);
	*line = NULL;
	if (ft_pos('\n', save) >=  0)
	{
		*line = ft_substr(save, 0, ft_pos('\n', save));
		save = ft_substr(save, ft_pos('\n', save) + 1,
		ft_strlen(save) - ft_pos('\n', save));
		return(1);
	}
	if (!(buff = malloc(BUFFER_SIZE + 1)))
			return (-1);
	else
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		if ((rd = read(fd, buff, BUFFER_SIZE)) < 0)
			return (rd);
		if (rd < BUFFER_SIZE && ft_pos('\n', buff) < 0)
		{
		save = ft_strjoin(save, buff);
		*line = ft_substr(save, 0, ft_pos('\n', save));
		*save = 0;
		return(0);
		}
		save = ft_strjoin(save, buff);
		return (get_next_line(fd, line));
	}	
}
 