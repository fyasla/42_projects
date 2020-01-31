/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:13:06 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/31 19:30:27 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		draw(t_win *w, t_scene *scene, int cam)
{
	int	i;
	int	j;

	i = 0;
	while (i < scene->resx)
	{
		j = 0;
		while (j < scene->resy)
		{
			mlx_pixel_put(w->mlx_p, w->win_p, i, j, pix_col(i, j, scene, cam));
			j++;
		}
		i++;
	}
	return (0);
}
