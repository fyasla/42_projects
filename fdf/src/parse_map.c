/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:08:39 by faysal            #+#    #+#             */
/*   Updated: 2021/09/29 21:25:29 by faysal           ###   ########.fr       */
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
	if (fd < 0)
		open_error();
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
	printf("%d\n", n);
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

int	line_length(int i, char *filename, int r_nb)
{
	int		fd;
	char	*line;
	char	**split;
	int		n;

	n = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		open_error();
	get_next_line(fd, &line);
	while (ft_strlen(line) == 0)
	{
		free(line);
		get_next_line(fd, &line);
	}
	while (n < r_nb && n < i)
	{
		free(line);
		line = 0;
		get_next_line(fd, &line);
		while (ft_strlen(line) == 0)
		{
			get_next_line(fd, &line);
			free(line);
		}
		n++;
	}
	split = ft_split(line, ' ');
	if (!split)
		close3(split);
	n = count_words(split);
	close(fd);
	tab_line_free(line, split);
	return (n);
}

t_point	**map_alloc(char *filename, int r_nb)
{
	t_point	**map;
	int		i;
	int		l_l;

	i = 0;
	map = malloc(sizeof(t_point *) * (r_nb + 1));
	if (!map)
		return (NULL);
	while (i < r_nb)
	{
		l_l = line_length(i, filename, r_nb);
		map[i] = malloc(sizeof(t_point) * (l_l + 1));
		if (!map[i])
			return (NULL);
		i++;
	}
	map[i] = malloc(sizeof(t_point));
	if (!map[i])
		return (NULL);
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
