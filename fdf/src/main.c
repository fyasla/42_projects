/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:08:26 by faysal            #+#    #+#             */
/*   Updated: 2021/09/21 23:34:59 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// int	main(void)
// {
// 	t_window	win;
// 	t_point	p0;
// 	t_point	p1;
// 	int	a;
// 	int b;
// 	int c;

// 	a = sizeof(unsigned int);
// 	b = (RESX - 2 * MARGIN)* sizeof(unsigned int);
// 	c = 1;
// 	p0.x = 200;
// 	p0.y = 200;
// 	p1.x = 0;
// 	p1.y = 0;
// 	if (p0.x < 0 || p1.x <0 || p0.y < 0 || p1.y < 0)
// 		return (-1);
// 	win.mlx_ptr = mlx_init();
// 	win.win_ptr = mlx_new_window(win.mlx_ptr, RESX, RESX, "Mon titre");
// 	win.img_ptr = mlx_new_image(win.mlx_ptr, RESX - 2 * MARGIN, RESY - 2 * MARGIN);
// 	win.img = mlx_get_data_addr(win.img_ptr, &a, &b, &c);

// 	plot_line(p0, p1, &win);
// 	mlx_put_image_to_window (win.mlx_ptr, win.win_ptr, win.img_ptr, MARGIN, MARGIN);
// 	mlx_loop(win.mlx_ptr);
// 	return (0);
// }

#include <stdio.h>

int	main(int ac, char **av)
{
	int			nb;
	int			i;
	int			j;
	t_point	***map;

	if (ac == 1 || ac > 2)
		return (0);
	nb = row_nb(av[1]);
	printf("%d\n", nb);
	map = parse_map(av[1]);
	map_to_iso(map, nb, col_nb(av[1]));
	resize_map(map, nb, col_nb(av[1]));
	i = 0;
	while (i < nb)
	{
		j = 0;
		while (j < 18)
		{
			printf("%d ", map[i][j]->x);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
