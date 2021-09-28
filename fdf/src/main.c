/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:08:26 by faysal            #+#    #+#             */
/*   Updated: 2021/09/28 20:12:47 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw(t_window *win, char *filename)
{
	t_point	**map;
	int		r_nb;

	r_nb = row_nb(filename);
	map = map_alloc(filename);
	fill_map(map, filename);
	set_color_map(map, filename);
	map_to_iso(map, filename, r_nb);
	resize_map(map, r_nb, filename);
	plot_map(map, filename, r_nb, win);
}

void	win_init(t_window *w, char *filename)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	bits_per_pixel = sizeof(unsigned int);
	size_line = (RESX - 2 * MARGIN) * bits_per_pixel;
	endian = 0;
	w->mlx_p = mlx_init();
	w->w_p = mlx_new_window(w->mlx_p, RESX, RESY, "Mon titre");
	w->img_p = mlx_new_image(w->mlx_p, RESX - 2 * MARGIN, RESY - 2 * MARGIN);
	w->img = mlx_get_data_addr(w->img_p, &bits_per_pixel, &size_line, &endian);
	draw(w, filename);
	mlx_put_image_to_window (w->mlx_p, w->w_p, w->img_p, MARGIN, MARGIN);
}

int	main(int ac, char **av)
{
	t_window	win;

	(void)av;
	if (ac != 2)
		return (0);
	win_init(&win, av[1]);
	mlx_loop(win.mlx_p);
	return (0);
}
