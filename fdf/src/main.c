/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:08:26 by faysal            #+#    #+#             */
/*   Updated: 2021/09/22 16:11:51 by faysal           ###   ########.fr       */
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
// 	win.win_ptr = mlx_new_window(win.mlx_ptr, RESX, RESY, "Mon titre");
// 	win.img_ptr = mlx_new_image(win.mlx_ptr, RESX - 2 * MARGIN, RESY - 2 * MARGIN);
// 	win.img = mlx_get_data_addr(win.img_ptr, &a, &b, &c);

// 	plot_line(p0, p1, &win);
// 	mlx_put_image_to_window (win.mlx_ptr, win.win_ptr, win.img_ptr, MARGIN, MARGIN);
// 	mlx_loop(win.mlx_ptr);
// 	return (0);
// }

int	main(int ac, char **av)
{
	int			r_nb;
	int			c_nb;
	int			i;
	int			j;
	t_point	***map;

	if (ac == 1 || ac > 2)
		return (0);
	r_nb = row_nb(av[1]);
	c_nb = col_nb(av[1]);
	map = parse_map(av[1]);
	map_to_iso(map, r_nb, col_nb(av[1]));
	resize_map(map, r_nb, col_nb(av[1]));
	//map[0][0]->x = 20;
	//map[0][0]->y = 20;

	t_point pmin;
	t_point pmax;

	pmin = p_min(map, r_nb, c_nb);
	pmax = p_max(map, r_nb, c_nb);
	printf("\nminx: %f  maxx: %f \nminy: %f maxy:%f\n", pmin.x, pmax.x, pmin.y, pmax.y);




	t_window	win;
	int	a;
	int b;
	int c;

	a = sizeof(unsigned int);
	b = (RESX - 2 * MARGIN)* sizeof(unsigned int);
	c = 1;
	
	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, RESX, RESY, "Mon titre");
	win.img_ptr = mlx_new_image(win.mlx_ptr, RESX - 2 * MARGIN, RESY - 2 * MARGIN);
	win.img = mlx_get_data_addr(win.img_ptr, &a, &b, &c);
	
	plot_map(map, r_nb, c_nb, &win);
	mlx_put_image_to_window (win.mlx_ptr, win.win_ptr, win.img_ptr, MARGIN, MARGIN);
	mlx_loop(win.mlx_ptr);
	
	
	
	
	
	i = 0;
	while (i < r_nb)
	{
		j = 0;
		while (j < c_nb)
		{
			printf("%f ", map[i][j]->x);
			j++;
		}
		printf("\n");
		i++;
	}

	printf("\n");
	i = 0;
	while (i < r_nb)
	{
		j = 0;
		while (j < c_nb)
		{
			printf("%f ", map[i][j]->y);
			j++;
		}
		printf("\n");
		i++;
	}
	
	// char **s;
	// int	i;
	// (void)ac;

	// i = 0;
	// s = ft_split(av[1], ' ');
	// while (s[i])
	// {
	// 	printf("%s\n", s[i]);
	// 	i++;
	// }
	// i = 0;
	// while (s[i])
	// {
	// 	free(s[i]);
	// 	i++;
	// }
	// free(s[i]);
	// free(s);
	return (0);
}
