/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 22:20:48 by faysal            #+#    #+#             */
/*   Updated: 2021/09/29 14:09:45 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	handle_events(t_window *win, t_point **map)
{
	mlx_key_hook(win->w_p, key_press, map);
	mlx_hook(win->w_p, 17, 0, close2, map);
}

int	close2(t_point **map)
{
	free_map(map);
	exit(0);
}

int	close3(char **split)
{
	free_tab((void **)split);
	exit(0);
}

int	key_press(int key, void *param)
{
	(void)param;
	if (key == 65307)
		close2(param);
	return (0);
}

void	open_error(void)
{
	perror("Open: ");
	exit(0);
}
