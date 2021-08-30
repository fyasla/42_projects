/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:13:46 by faysal            #+#    #+#             */
/*   Updated: 2021/08/30 20:51:17 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	plot_line_low(t_point p0, t_point p1, t_window window)
{
	int	dx;
	int	dy;
	int	yi;
	int	d;
	int	y;
	int	x;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = (2 * dy) - dx;
	y = p0.y;
	x = p0.x;
	while (x <= p1.x)
	{
		mlx_pixel_put(window.mlx_ptr, window.win_ptr, x, y, 255);
		if (d > 0)
		{
			y = y + yi;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + 2 * dy;
		x++;
	}
}

void	plot_line_high(t_point p0, t_point p1, t_window window)
{
	int	dx;
	int	dy;
	int	xi;
	int	d;
	int	y;
	int	x;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = (2 * dx) - dy;
	y = p0.y;
	x = p0.x;
	while (y <= p1.y)
	{
		mlx_pixel_put(window.mlx_ptr, window.win_ptr, x, y, 255);
		if (d > 0)
		{
			x = x + xi;
			d = d + (2 * (dx - dy));
		}
		else
			d = d + 2 * dx;
		y++;
	}
}

void	plot_line(t_point p0, t_point p1, t_window window)
{
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			plot_line_low(p1, p0, window);
		else
			plot_line_low(p0, p1, window);
	}
	else
	{
		if (p0.y > p1.y)
			plot_line_high(p1, p0, window);
		else
			plot_line_high(p0, p1, window);
	}
}
