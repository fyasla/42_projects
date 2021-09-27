/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:22:05 by faysal            #+#    #+#             */
/*   Updated: 2021/09/27 02:42:22 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	p_min(t_point **map, int row_nb, char *filename)
{
	int		i;
	int		j;
	t_point	p_min;
	int		l_l;

	i = 0;
	p_min = map[0][0];
	while (i < row_nb)
	{
		j = 0;
		l_l = line_length(i, filename);
		while (j < l_l)
		{
			if (map[i][j].x < p_min.x)
				p_min.x = map[i][j].x;
			if (map[i][j].y < p_min.y)
				p_min.y = map[i][j].y;
			if (map[i][j].z < p_min.z)
				p_min.z = map[i][j].z;
			j++;
		}
		i++;
	}
	return (p_min);
}

t_point	p_max(t_point **map, int row_nb, char *filename)
{
	int		i;
	int		j;
	t_point	p_max;
	int		l_l;

	i = 0;
	p_max = map[0][0];
	while (i < row_nb)
	{
		j = 0;
		l_l = line_length(i, filename);
		while (j < l_l)
		{
			if (map[i][j].x > p_max.x)
				p_max.x = map[i][j].x;
			if (map[i][j].y > p_max.y)
				p_max.y = map[i][j].y;
			if (map[i][j].z > p_max.z)
				p_max.z = map[i][j].z;
			j++;
		}
		i++;
	}
	return (p_max);
}

void	resize_map(t_point **map, int row_nb, char *filename)
{
	int		i;
	int		j;
	t_point	min;
	t_point	max;
	int		l_l;

	i = 0;
	min = p_min(map, row_nb, filename);
	max = p_max(map, row_nb, filename);
	while (i < row_nb)
	{
		j = 0;
		l_l = line_length(i, filename);
		while (j < l_l)
		{
			map[i][j] = *resize_p(map[i][j], min, max);
			j++;
		}
		i++;
	}
}

t_point	*resize_p(t_point p, t_point min, t_point max)
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	if (!new)
		return (NULL);
	new->x = ((RESY - 100) * (p.x - min.x)) / (max.x - min.x) + 50;
	new->y = ((RESX - 100) * (p.y - min.y)) / (max.y - min.y) + 50;
	new->z = p.z;
	new->color = p.color;
	return (new);
}