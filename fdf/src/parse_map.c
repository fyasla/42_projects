/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:08:39 by faysal            #+#    #+#             */
/*   Updated: 2021/09/27 13:28:49 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	row_nb(char *filename)
{
	int		fd;
	int		ret;
	char	*line;
	int		n;

	fd = open(filename, O_RDONLY);
	n = 0;
	ret = get_next_line(fd, &line);
	while (ret > 0 && ft_strlen(line) > 0)
	{
		n++;
		free(line);
		ret = get_next_line(fd, &line);
	}
	if (ft_strlen(line) > 0)
		n++;
	free(line);
	close(fd);
	return (n);
}

int	count_words(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

int	line_length(int i, char *filename)
{
	int		fd;
	int		ret;
	char	*line;
	char	**split;
	int		n;

	n = 0;
	fd = open(filename, O_RDONLY);
	ret = get_next_line(fd, &line);
	while (ret > 0 && n < i)
	{
		free(line);
		line = 0;
		ret = get_next_line(fd, &line);
		n++;
	}
	split = ft_split(line, ' ');
	n = count_words(split);
	close(fd);
	free(line);
	free_tab(split);
	return (n);
}

t_point	**map_alloc(char *filename)
{
	t_point	**map;
	int		i;
	int		r_nb;

	i = 0;
	r_nb = row_nb(filename);
	map = malloc(sizeof(t_point *) * (r_nb + 1));
	if (!map)
		return (NULL);
	while (i <= r_nb)
	{
		map[i] = malloc(sizeof(t_point) * (line_length(i, filename) + 1));
		if (!map[i])
			return (NULL);
		i++;
	}
	return (map);
}

t_point	coord(int x, int y, int z)
{
	t_point	p;

	p.x = (double)x;
	p.y = (double)y;
	p.z = (double)z;
	p.set = 1;
	return (p);
}
