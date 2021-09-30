/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:08:39 by faysal            #+#    #+#             */
/*   Updated: 2021/09/30 20:27:05 by faysal           ###   ########.fr       */
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
	if (fd < 0 || read(fd, line, 0) < 0)
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

int	*line_lengths(char *filename, int r_nb)
{
	int		*tab;
	int		fd;
	char	*line;
	char	**split;
	int		i;

	tab = malloc(r_nb * sizeof(int));
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0 || read(fd, line, 0) < 0)
		open_error();
	get_next_line_protect(&fd, &line);
	while (i < r_nb)
	{
		split = ft_split(line, ' ');
		if (!split)
			close3(split);
		tab[i] = count_words(split);
		tab_line_free(line, split);
		get_next_line_protect(&fd, &line);
		i++;
	}
	free(line);
	close(fd);
	return (tab);
}

t_point	**map_alloc(int r_nb, int *lls)
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
		l_l = lls[i];
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
