/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:06:31 by faysal            #+#    #+#             */
/*   Updated: 2021/09/02 11:53:09 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	word_nb(char **split)
{
	int	n;

	n = 0;
	while (split[n] != NULL)
		n++;
	return (n);
}

int	row_nb(char *filename)
{
	int		n;
	int		fd;
	int		ret;
	char	*line;

	n = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror("open error");
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		free(line);
		line = 0;
		ret = get_next_line(fd, &line);
		n++;
	}
	free(line);
	if (close(fd) < 0)
		perror ("close error");
	return (n);
}

int	col_nb(char *filename)
{
	int		n;
	int		fd;
	int		ret;
	char	*line;
	char	**split;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror("open error");
	ret = get_next_line(fd, &line);
	split = ft_split(line, ' ');
	n = word_nb(split);
	while (ret > 0)
	{
		free(line);
		line = 0;
		ret = get_next_line(fd, &line);
		split = ft_split(line, ' ');
		if (n != word_nb(split))
			perror("The map is not an error");
	}
	free(line);
	if (close(fd) < 0)
		perror ("close error");
	return (n);
}

t_point	***parse_map(char *filename)
{
	t_point		***map;
	int			i;
	int			j;
	char		*line;
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror("open error");
	map = malloc(row_nb(filename) * sizeof(t_point **));
	i = 0;
	while (get_next_line(fd, &line) >= 0)
	{
		j = 0;
		map[i] = malloc(col_nb(filename) * sizeof(t_point *));
		while (ft_split(line, ' ')[j] != NULL)
		{
			map[i][j] = p_coord(i, j, ft_atoi(ft_split(line, ' ')[j]));
			j++;
		}
		free(line);
		line = 0;
		i++;
	}
	free(line);
	return (map);
}

t_point	*p_coord(int x, int y, int z)
{
	t_point	*p;

	p = malloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	p->z = z;
	return (p);
}
