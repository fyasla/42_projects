/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:28:08 by fbougama          #+#    #+#             */
/*   Updated: 2020/06/20 14:14:56 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		deal_key(int key, t_win *win)
{
	if (key == 65307)
		exit_prog(win);
	else if (key == 65361 || key == 65363)
		deal_cam(key, win);
	return (0);
}

int		exit_prog(t_win *win)
{
	mlx_destroy_window(win->mlx_p, win->win_p);
	exit(EXIT_SUCCESS);
	return (0);
}

int		deal_cam(int key, t_win *win)
{
	t_scene	*scene;
	char	*img;

	img = win->img;
	scene = win->scene;
	if (key == 65363)
	{
		scene->cam = (scene->cam == (scene->cpt[1] - 1)) ? 0 : (scene->cam + 1);
		draw(win, scene, img);
	}
	else if (key == 65361)
	{
		scene->cam = (scene->cam == 0) ? (scene->cpt[1] - 1) : (scene->cam - 1);
		draw(win, scene, img);
	}
	return (0);
}
