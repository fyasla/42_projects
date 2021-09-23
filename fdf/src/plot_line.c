/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:13:46 by faysal            #+#    #+#             */
/*   Updated: 2021/09/23 14:19:07 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	plot_line_low(t_point p0, t_point p1, t_window *window)
{
	int	dx;
	int	dy;
	int	yi;
	t_point	p;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	p.z = (2 * dy) - dx;
	p.y = p0.y;
	p.x = p0.x;
	while (p.x <= p1.x)
	{
		color_rgb(window, p.x, p.y, 0xFFFFFF);
		if (p.z > 0)
		{
			p.y = p.y + yi;
			p.z = p.z + (2 * (dy - dx));
		}
		else
			p.z = p.z + 2 * dy;
		p.x++;
	}
}

void	plot_line_high(t_point p0, t_point p1, t_window *window)
{
	int		dx;
	int		dy;
	int		xi;
	t_point	p;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	p.z = (2 * dx) - dy;
	p.y = p0.y;
	p.x = p0.x;
	while (p.y <= p1.y)
	{
		color_rgb(window, p.x, p.y, 0xFFFFFF);
		if (p.z > 0)
		{
			p.x = p.x + xi;
			p.z = p.z + (2 * (dx - dy));
		}
		else
			p.z = p.z + 2 * dx;
		p.y++;
	}
}

void	plot_line(t_point p0, t_point p1, t_window *window)
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
