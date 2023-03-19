/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:46:19 by faysal            #+#    #+#             */
/*   Updated: 2021/10/03 20:23:05 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	fill_map(t_point **map, char *filename, int r_nb)
{
	t_inc	p;
	char	*line;
	int		fd;
	char	**split;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || read(fd, line, 0) < 0)
		open_error();
	p.i = 0;
	while (p.i < r_nb)
	{
		get_next_line(fd, &line);
		while (ft_strlen(line) == 0)
		{
			free(line);
			get_next_line(fd, &line);
		}
		split = ft_split(line, ' ');
		split_loop(&(p.i), &(p.j), &split, map);
		tab_line_free(line, split);
		free(line);
		p.i++;
	}
	map[p.i][0].set = -1;
	close(fd);
}

void	set_color_map(t_point **map, int r_nb)
{
	int	i;
	int	j;

	i = 0;
	while (map[i][0].set > 0)
	{
		j = 0;
		while (map[i][j].set == 1)
		{
			map[i][j].color = set_color_p(map[i][j], map, r_nb);
			j++;
		}
		i++;
	}
}

void	free_tab(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	if (tab)
		free(tab);
}

void	free_map(t_point **map)
{
	int	i;

	i = 0;
	while (map[i][0].set > 0)
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	if (map)
		free(map);
}

void	split_loop(int *i, int *j, char ***split, t_point **map)
{
	if (!(*split))
	{
		free_tab((void **)split);
		close2(map);
	}
	*j = 0;
	while ((*split)[*j] != NULL)
	{
		map[*i][*j] = coord(*i, *j, ft_atoi((*split)[*j]));
		(*j)++;
	}
	map[*i][*j].set = 0;
}
