/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:13:46 by faysal            #+#    #+#             */
/*   Updated: 2021/09/27 13:00:49 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	update_coordinates(t_point *p, int x, int y, int z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

void	plot_line_low(t_point p0, t_point p1, t_window *window)
{
	t_point	d;
	t_point	p;
	int		yi;

	d.x = p1.x - p0.x;
	d.y = p1.y - p0.y;
	yi = 1;
	if (d.y < 0)
	{
		yi = -1;
		d.y = -d.y;
	}
	update_coordinates(&p, p0.x, p0.y, (2 * d.y) - d.x);
	while (p.x <= p1.x)
	{
		color_rgb(window, p.x, p.y, p0.color);
		if (p.z > 0)
		{
			p.y = p.y + yi;
			p.z = p.z + (2 * (d.y - d.x));
		}
		else
			p.z = p.z + 2 * d.y;
		p.x++;
	}
}

void	plot_line_high(t_point p0, t_point p1, t_window *window)
{
	t_point	d;
	t_point	p;
	int		xi;

	d.x = p1.x - p0.x;
	d.y = p1.y - p0.y;
	xi = 1;
	if (d.x < 0)
	{
		xi = -1;
		d.x = -d.x;
	}
	update_coordinates(&p, p0.x, p0.y, (2 * d.x) - d.y);
	while (p.y <= p1.y)
	{
		color_rgb(window, p.x, p.y, p0.color);
		if (p.z > 0)
		{
			p.x = p.x + xi;
			p.z = p.z + (2 * (d.x - d.y));
		}
		else
			p.z = p.z + 2 * d.x;
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
