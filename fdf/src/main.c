/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:08:26 by faysal            #+#    #+#             */
/*   Updated: 2021/09/23 14:20:24 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// int	main(int ac, char **av)
// {
// 	int			r_nb;
// 	int			c_nb;
// 	int			i;
// 	int			j;
// 	t_point	***map;

// 	if (ac == 1 || ac > 2)
// 		return (0);
// 	r_nb = row_nb(av[1]);
// 	c_nb = col_nb(av[1]);
// 	map = parse_map(av[1]);
// 	map_to_iso(map, r_nb, col_nb(av[1]));
// 	resize_map(map, r_nb, col_nb(av[1]));
// 	t_point pmin;
// 	t_point pmax;

// 	pmin = p_min(map, r_nb, c_nb);
// 	pmax = p_max(map, r_nb, c_nb);
// 	printf("\nminx: %f  maxx: %f \nminy: %f maxy:%f\n", pmin.x, pmax.x, pmin.y, pmax.y);




// 	t_window	win;
// 	int	a;
// 	int b;
// 	int c;

// 	a = sizeof(unsigned int);
// 	b = (RESX - 2 * MARGIN)* sizeof(unsigned int);
// 	c = 1;
	
// 	win.mlx_ptr = mlx_init();
// 	win.win_ptr = mlx_new_window(win.mlx_ptr, RESX, RESY, "Mon titre");
// 	win.img_ptr = mlx_new_image(win.mlx_ptr, RESX - 2 * MARGIN, RESY - 2 * MARGIN);
// 	win.img = mlx_get_data_addr(win.img_ptr, &a, &b, &c);
	
// 	plot_map(map, r_nb, c_nb, &win);
// 	mlx_put_image_to_window (win.mlx_ptr, win.win_ptr, win.img_ptr, MARGIN, MARGIN);
// 	mlx_loop(win.mlx_ptr);
// 	return (0);
// }

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

void	win_init(t_window *win)
{
	int	bits_per_pixel;
	int size_line;
	int endian;

	bits_per_pixel = sizeof(unsigned int);
	size_line = (RESX - 2 * MARGIN) * bits_per_pixel;
	endian = 1;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, RESX, RESY, "Mon titre");
	win->img_ptr = mlx_new_image(win->mlx_ptr, RESX - 2 * MARGIN, RESY - 2 * MARGIN);
	win->img = mlx_get_data_addr(win->img_ptr, &bits_per_pixel, &size_line, &endian);
	draw(win);
	mlx_put_image_to_window (win->mlx_ptr, win->win_ptr, win->img_ptr, MARGIN, MARGIN);
}

int	main(int ac, char **av)
{
	t_window	win;
	(void)av;

	if (ac != 2)
		return (0);
	win_init(&win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
