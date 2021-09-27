/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:43:30 by faysal            #+#    #+#             */
/*   Updated: 2021/09/27 18:57:39 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	color_rgb(t_window *win, int x, int y, int rgb)
{
	win->img[x * (RESX - 2 * MARGIN) * 4 + y * 4] = (rgb >> 0);
	win->img[x * (RESX - 2 * MARGIN) * 4 + y * 4 + 1] = rgb >> 8;
	win->img[x * (RESX - 2 * MARGIN) * 4 + y * 4 + 2] = (rgb >> 16);
}

int	set_color_p(t_point p, t_point **map, char *filename, int r_nb)
{
	t_point	min;
	t_point	max;
	int 	color;

	min = p_min(map, r_nb, filename);
	max = p_max(map, r_nb, filename);
	color = 1000 + 1000 * (p.z - min.z) / (max.z - min.z);
	ft_putnbr_fd(1, p.z);
	ft_putstr_fd(" ", 1);
	(void)map;
	(void)filename;
	(void)p;
	//(void)r_nb;
	//color = 0xffffff;
	return (color);
}
