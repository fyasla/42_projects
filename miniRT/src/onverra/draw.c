/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:13:06 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/05 14:17:14 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		draw(t_win *w, t_scene *scene, int cam)
{
	t_pix	pix;

	pix.x = 0;
	while (pix.x < scene->resx)
	{
		pix.y = 0;
		while (pix.y < scene->resy)
		{
			mlx_pixel_put(w->mlx_p, w->win_p, pix.x, pix.y, pix_col(pix, scene, cam));
			pix.y++;
		}
		pix.x++;
	}
	return (0);
}
