/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:28:08 by fbougama          #+#    #+#             */
/*   Updated: 2020/03/11 15:29:11 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		deal_key(int key, t_win *win)
{
	t_scene	*scene;
	char	*img;

	img = win->img;
	scene = win->scene;
	if (key == 53)
		exit_prog(0, win);
	else if (key == 8)
	{
		scene->cam = (scene->cam == (scene->cpt[1] - 1)) ? 0 : (scene->cam + 1);
		// scene->cam = 1;
		draw2(win, scene, img);
	}
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

