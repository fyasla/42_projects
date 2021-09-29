/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:20:30 by faysal            #+#    #+#             */
/*   Updated: 2021/09/29 21:23:09 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	plot_right(t_point **map, int i, int j, t_window *win)
{
	t_point	p0;
	t_point	p1;

	p0 = map[i][j];
	p1 = map[i][j + 1];
	plot_line(p0, p1, win);
}

void	plot_low(t_point **map, int i, int j, t_window *win)
{
	t_point	p0;
	t_point	p1;

	p0 = map[i][j];
	p1 = map[i + 1][j];
	plot_line(p0, p1, win);
}

void	plot_map(t_point **map, char *filename, int r_nb, t_window *win)
{
	int	i;
	int	j;
	int	l_l;
	int	l_l1;

	i = 0;
	l_l1 = line_length(0, filename, r_nb);
	while (i < r_nb)
	{
		j = 0;
		l_l = l_l1;
		if (i < r_nb - 1)
			l_l1 = line_length(i + 1, filename, r_nb);
		while (j < l_l)
		{
			if (j < l_l - 1)
				plot_right(map, i, j, win);
			if (i < r_nb - 1 && j < l_l1)
				plot_low(map, i, j, win);
			j++;
		}
		i++;
	}
}
