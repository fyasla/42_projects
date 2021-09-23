/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:43:30 by faysal            #+#    #+#             */
/*   Updated: 2021/09/23 14:17:36 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	color_rgb(t_window *win, int x, int y, int rgb)
{
	win->img[x * (RESX - 2 * MARGIN) * 4 + y * 4] = (rgb >> 0);
	win->img[x * (RESX - 2 * MARGIN) * 4 + y * 4 + 1] = rgb >> 8;
	win->img[x * (RESX - 2 * MARGIN) * 4 + y * 4 + 2] = (rgb >> 16);
}

int	color_z(int z)
{
	return (z);
}
