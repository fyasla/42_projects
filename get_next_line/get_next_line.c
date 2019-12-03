/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:33:58 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/03 15:45:45 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buff;
	int			rd;
	int			pos;

	rd = 1;
	*line = NULL;
	if (BUFFER_SIZE < 1 || !line || fd < 0)
		return (-1);
	while (((pos = ft_pos('\n', save)) == -1) && rd > 0)
	{
		if (!(buff = (char*)malloc(BUFFER_SIZE + 1)))
			return (-1);
		ft_bzero(buff, BUFFER_SIZE + 1);
		if ((rd = read(fd, buff, BUFFER_SIZE)) == -1)
			return (-1);
		save = ft_strjoin(save, buff);
		//free(tmp);
		//free(buff);
	}
	if (pos == -1)
		pos = ft_strlen(save);
	*line = ft_substr(save, 0, pos);
	save = ft_substr(save, pos + 1, ft_strlen(save));
	if (rd == 0)
		return (0);
	else
		return (1);
}
