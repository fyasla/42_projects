/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:22:05 by faysal            #+#    #+#             */
/*   Updated: 2021/09/30 01:20:27 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	p_min(t_point **map, int row_nb)
{
	int		i;
	int		j;
	t_point	p_min;

	i = 0;
	p_min = map[0][0];
	while (i < row_nb)
	{
		j = 0;
		while (map[i][j].set == 1)
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

t_point	p_max(t_point **map, int row_nb)
{
	int		i;
	int		j;
	t_point	p_max;

	i = 0;
	p_max = map[0][0];
	while (i < row_nb)
	{
		j = 0;
		while (map[i][j].set == 1)
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

void	resize_map(t_point **map, int row_nb, int *lls)
{
	int		i;
	int		j;
	t_point	min;
	t_point	max;
	int		l_l;

	i = 0;
	min = p_min(map, row_nb);
	max = p_max(map, row_nb);
	while (i < row_nb)
	{
		j = 0;
		l_l = lls[i];
		while (j < l_l)
		{
			map[i][j] = resize_p(map[i][j], min, max);
			j++;
		}
		i++;
	}
}

t_point	resize_p(t_point p, t_point min, t_point max)
{
	t_point	new;

	new.x = ((700 - 100) * (p.x - min.x)) / (max.x - min.x) + 50;
	new.y = ((1300 - 100) * (p.y - min.y)) / (max.y - min.y) + 50;
	new.z = p.z;
	new.color = p.color;
	new.set = p.set;
	return (new);
}
