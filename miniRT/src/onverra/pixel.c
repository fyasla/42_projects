/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:32:17 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/31 21:31:30 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		pix_col(int	x, int y, t_scene *scene, int cam)
{
	
}

t_vec3	rstr_to_cam(int x, int y, t_scene *scene)
{
	t_vec3	cam_crd;
	double	img_rat;

	img_rat = (double)scene->x / scene->y;
	cam_crd.x = (2 * x - 1) * img_rat * tan(to_rad(scene->fov / 2));
	cam_crd.y = (1 - 2 * y) * tan(to_rad(scene->fov / 2));
	cam_crd.z = -1;
	return (cam_crd);
}

t_vec3	cam_to_world(t_vec3 cam_crd, t_cam cam)
{
	return (cam_crd);
}
