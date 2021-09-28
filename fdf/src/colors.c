/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:43:30 by faysal            #+#    #+#             */
/*   Updated: 2021/09/28 20:59:34 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	rgb(t_window *win, int x, int y, int rgb)
{
	win->img[x * (RESX - 2 * MARGIN) * 4 + y * 4] = rgb >> 0;
	win->img[x * (RESX - 2 * MARGIN) * 4 + y * 4 + 1] = rgb >> 8;
	win->img[x * (RESX - 2 * MARGIN) * 4 + y * 4 + 2] = rgb >> 16;
}

int	set_color_p(t_point p, t_point **map, char *filename, int r_nb)
{
	t_point	min;
	t_point	max;
	int		color;
	double	pos;

	min = p_min(map, r_nb);
	max = p_max(map, r_nb);
	pos = 0;
	if (max.z > min.z)
		pos = (p.z - min.z) / (max.z - min.z);
	color = c_g(COL1, COL2, pos);
	return (color);
}

int	c_g(int c1, int c2, double p)
{
	int	c;
	int	red;
	int	g;
	int	blue;

	red = c1 / 0x010000 + (c2 / 0x010000 - c1 / 0x010000) * p;
	g = (c1 % 0x010000) / 0x000100;
	g = g + ((c2 % 0x010000) / 0x000100 - (c1 % 0x010000) / 0x000100) * p;
	blue = c1 % 0x000100 + (c2 % 0x000100 - c1 % 0x000100 ) * p;
	c = red * 0x010000 + g * 0x000100 + blue;
	return (c);
}
