/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:15:03 by fbougama          #+#    #+#             */
/*   Updated: 2020/03/02 13:33:39 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int		deal_key(int key, t_win *win)
{
	if (key == 53)
		exit_prog(0, win);
	return (0);
}

int		exit_prog(int n, t_win *win)
{
	if (n == 0)
	{
		mlx_destroy_window(win->mlx_p, win->win_p);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_win	win;
	t_scene *scene_ptr;
	int		map_fd;
	int		cam;

	if (ac < 2)
	{
		ft_printf("You should pass a map as argument\n");
		return (0);
	}
	cam = 0;
	map_fd = open(av[1], O_RDONLY);
	scene_ptr = map_parse(map_fd);
	close(map_fd);

	win.mlx_p = mlx_init();
	win.win_p = mlx_new_window(win.mlx_p, scene_ptr->resx, scene_ptr->resy, av[1]);
	draw2(&win, scene_ptr, cam);
	mlx_key_hook(win.win_p, deal_key, &win);
	mlx_loop(win.mlx_p);
	return (0);
}
