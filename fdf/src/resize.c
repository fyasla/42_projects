/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:22:05 by faysal            #+#    #+#             */
/*   Updated: 2021/09/22 15:35:10 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	p_min(t_point ***map, int row_nb, int col_nb)
{
	int		i;
	int		j;
	t_point	p_min;

	i = 0;
	p_min = *map[0][0];
	while (i < row_nb)
	{
		j = 0;
		while (j < col_nb)
		{
			if (map[i][j]->x < p_min.x)
				p_min.x = map[i][j]->x;
			if (map[i][j]->y < p_min.y)
				p_min.y = map[i][j]->y;
			j++;
		}
		i++;
	}
	return (p_min);
}

t_point	p_max(t_point ***map, int row_nb, int col_nb)
{
	int		i;
	int		j;
	t_point	p_max;

	i = 0;
	p_max = *map[0][0];
	while (i < row_nb)
	{
		j = 0;
		while (j < col_nb)
		{
			if (map[i][j]->x > p_max.x)
				p_max.x = map[i][j]->x;
			if (map[i][j]->y > p_max.y)
				p_max.y = map[i][j]->y;
			j++;
		}
		i++;
	}
	return (p_max);
}

void	resize_map(t_point ***map, int row_nb, int col_nb)
{
	int		i;
	int		j;
	t_point	min;
	t_point	max;

	i = 0;
	min = p_min(map, row_nb, col_nb);
	max = p_max(map, row_nb, col_nb);
	while (i < row_nb)
	{
		j = 0;
		while (j < col_nb)
		{
			*map[i][j] = *resize_p(*map[i][j], min, max);
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
	new->x = (RESX * (p.x - min.x)) / (max.x +1- min.x);
	new->y = (RESY * (p.y - min.y)) / (max.y +1- min.y);
	return (new);
}