/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:22:05 by faysal            #+#    #+#             */
/*   Updated: 2021/09/02 12:05:05 by faysal           ###   ########.fr       */
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
	}
	return (p_max);
}

void	resize_map(t_point ***map, int row_nb, int col_nb)
{
	int	i;
	int	j;

	i = 0;
	while (i < row_nb)
	{
		j = 0;
		while (j < row_nb)
		{
			*map[i][j] = resize_p(*map[i][j]);
			j++;
		}
	}
}

t_point	resize_p(t_point p)
{
	t_point	new;

	
}