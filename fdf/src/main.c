/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:08:26 by faysal            #+#    #+#             */
/*   Updated: 2021/09/23 14:34:07 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw(t_window *win)
{
	t_point	p0;
	t_point	p1;
	t_point	p2;

	p0.x = 20;
	p0.y = 300;
	p1.x = 500;
	p1.y = 50;
	p2.x = 0;
	p2.y = 0;
	plot_line(p0, p1, win);
	plot_line(p2, p1, win);
}

void	win_init(t_window *w)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	bits_per_pixel = sizeof(unsigned int);
	size_line = (RESX - 2 * MARGIN) * bits_per_pixel;
	endian = 1;
	w->mlx_p = mlx_init();
	w->w_p = mlx_new_window(w->mlx_p, RESX, RESY, "Mon titre");
	w->img_p = mlx_new_image(w->mlx_p, RESX - 2 * MARGIN, RESY - 2 * MARGIN);
	w->img = mlx_get_data_addr(w->img_p, &bits_per_pixel, &size_line, &endian);
	draw(w);
	mlx_put_image_to_window (w->mlx_p, w->w_p, w->img_p, MARGIN, MARGIN);
}

int	main(int ac, char **av)
{
	t_window	win;

	(void)av;
	if (ac != 2)
		return (0);
	win_init(&win);
	mlx_loop(win.mlx_p);
	return (0);
}
