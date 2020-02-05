/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:15:03 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/05 16:33:56 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int		deal_key(int key, t_win *t_win)
{
	mlx_pixel_put(t_win->mlx_p, t_win->win_p, key, key, 255);
	return (0);
}

int		main(int ac, char **av)
{
	t_win	win;
	t_scene *scene_ptr;
	int		map_fd;
	int		cam;

	cam = 0;
	map_fd = open(av[1], O_RDONLY);
	scene_ptr = map_parse(map_fd);
	close(map_fd);

	win.mlx_p = mlx_init();
	win.win_p = mlx_new_window(win.mlx_p, scene_ptr->resx, scene_ptr->resy, av[1]);
	//mlx_key_hook(win.win_ptr, deal_key, &win);
	draw(&win, scene_ptr, cam);
	mlx_loop(win.mlx_p);
	return (0);
}
