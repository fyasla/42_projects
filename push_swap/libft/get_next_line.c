/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:26:55 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/10 15:59:28 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free(char **line, char **buffer)
{
	free(*line);
	if (line && *line)
		*line = NULL;
	if (buffer)
		free(*buffer);
	if (buffer && *buffer)
		*buffer = NULL;
	return (-1);
}

int	ft_p(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_eol(char **line, char **save)
{
	char	*tmp;

	if (!(*line = ft_substr2(*save, 0, ft_p(*save))))
		return (ft_free(line, NULL));
	tmp = *save;
	*save = ft_substr2(*save, ft_p(*save) + 1, ft_sl(*save) - ft_p(*save) - 1);
	if (!(*save))
		return (ft_free(line, NULL));
	free(tmp);
	return (1);
}

int	ft_eof_gnl(char **line, char **save, char **buff, int rd)
{
	char	*tmp;

	if (rd == 0)
	{
		if (!(*line = ft_strjoin2(*save, *buff)))
			return (ft_free(line, buff));
		free(*save);
		*save = NULL;
	}
	else
	{
		tmp = *save;
		if (!(*save = ft_strjoin2(*save, *buff)))
			return (ft_free(line, buff));
		free(tmp);
	}
	free(*buff);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buff;
	int			rd;

	*line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (ft_p(save) >= 0)
		return (ft_eol(line, &save));
	else
	{
		if (!(buff = malloc(BUFFER_SIZE + 1)))
			return (ft_free(line, &buff));
		buff = ft_bzero2(buff, BUFFER_SIZE + 1);
		if ((rd = read(fd, buff, BUFFER_SIZE)) == -1)
			return (ft_free(line, &buff));
		else if (rd == 0)
			return (ft_eof_gnl(line, &save, &buff, rd));
		else
		{
			ft_eof_gnl(line, &save, &buff, rd);
			return (get_next_line(fd, line));
		}
	}
}
