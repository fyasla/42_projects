/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:32:17 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/05 14:15:13 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		pix_col(t_pix pix, t_scene *scene, int cam)
{
	return (0);
}

t_vec3	rstr_to_cam(t_pix pix, t_scene *scene, int cam)
{
	t_vec3	cam_crd;
	double	img_rat;

	img_rat = (double)scene->resx / scene->resy;
	cam_crd.x = (2 * pix.x - 1) * img_rat * tan(to_rad(scene->cameras[cam].fov / 2));
	cam_crd.z = -1;
	return (cam_crd);
}

t_vec3	cam_to_world(t_vec3 cam_crd, t_cam cam)
{
	t_vec3	world_crd;

	world_crd.z = mul_vec(-1, cam.ori);
	world_crd.x = cam.ori.x;
	world_crd.y = cam.ori.y;

	return (world_crd);
}

t_vec3	ray(t_pix pix, t_scene *scene, int cam)
{
	t_vec3	cam_crd;

	cam_crd = cam_to_world(rstr_to_cam(pix.x, pix.y, scene, cam), scene->cameras[cam]);

}