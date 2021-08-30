/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:08:26 by faysal            #+#    #+#             */
/*   Updated: 2021/08/30 20:49:23 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(void)
{
	t_window	window;
	t_point		p0;
	t_point		p1;

	p0.x = 200;
	p0.y = 200;
	p1.x = 40;
	p1.y = 40;
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, 500, 500, "Mon titre");
	plot_line(p0, p1, window);
	mlx_loop(window.mlx_ptr);
	return (0);
}
