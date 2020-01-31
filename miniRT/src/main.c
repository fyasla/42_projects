/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:15:03 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/31 18:22:14 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int		deal_key(int key, t_win *t_win_ptr)
{
	mlx_pixel_put(t_win_ptr->mlx_ptr, t_win_ptr->win_ptr, key, key, 255);
	return (0);
}

int		main()
{
	t_win	win;

	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, 1000, 500, "window title");
	mlx_key_hook(win.win_ptr, deal_key, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
