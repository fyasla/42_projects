/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:43:30 by faysal            #+#    #+#             */
/*   Updated: 2021/09/27 13:05:09 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	color_rgb(t_window *win, int x, int y, int rgb)
{
	win->img[x * (RESX - 2 * MARGIN) * 4 + y * 4] = (rgb >> 0);
	win->img[x * (RESX - 2 * MARGIN) * 4 + y * 4 + 1] = rgb >> 8;
	win->img[x * (RESX - 2 * MARGIN) * 4 + y * 4 + 2] = (rgb >> 16);
}

int	set_color_p(t_point p, t_point **map, char *filename)
{
	// t_point	min;
	// t_point	max;
	int 	color;
	// int		r_nb;

	// r_nb = row_nb(filename);
	// min = p_min(map, r_nb, filename);
	// max = p_max(map, r_nb, filename);
	// color = 0xffffff * (p.z - min.z) / (max.z - min.z);
	(void)map;
	(void)filename;
	color = 0x0000ff * p.z;
	return (color);
}
