/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:32:17 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/05 15:26:02 by fbougama         ###   ########.fr       */
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
	t_vec3	axe;

	axe = cam.ori;
	world_crd = mat_vec(mat_rot(axe), cam_crd);
	return (world_crd);
}

t_ray	pix_ray(t_pix pix, t_scene *scene, int cam)
{
	t_vec3	cam_crd;
	t_vec3	wrld_crd;
	t_ray	ray;

	cam_crd = rstr_to_cam(pix, scene, cam);
	wrld_crd = cam_to_world(cam_crd, scene->cameras[cam]);
	ray.start = scene->cameras[cam].pos;
	ray.dir = vec_sous(wrld_crd, ray.start);
	return (ray);
}