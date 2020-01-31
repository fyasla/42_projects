/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:13:06 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/31 19:39:50 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		draw(t_win *w, t_scene *scene, int cam)
{
	int	x;
	int	y;

	x= 0;
	while (x < scene->resx)
	{
		y = 0;
		while (y < scene->resy)
		{
			mlx_pixel_put(w->mlx_p, w->win_p, x, y, pix_col(x, y, scene, cam));
			y++;
		}
		x++;
	}
	return (0);
}
