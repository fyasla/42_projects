/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:32:17 by fbougama          #+#    #+#             */
/*   Updated: 2020/03/12 17:24:14 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_color	pix_col(t_pix pix, t_scene *scene, int cam)
{
	t_ray	ray;
	t_color	color;
	t_vec3	inter;
	t_vec3	normal;

	ray = pix_ray(pix, scene, cam);
	ray.clst = closest(ray, scene);
	ray.t = collision(ray, ray.clst);
	inter = vec_sum(ray.start, mul_vec(0.99999 * ray.t, ray.dir));
	normal = collision_normal(ray, scene);
	color = obj_illum(ray.clst.color, total_light(inter, ray, scene, normal));
	return (color);
}

t_vec3	rstr_to_cam(t_pix pix, t_scene *scene, int cam)
{
	t_vec3	cam_crd;
	double	img_rat;
	double	scrn_x;
	double	scrn_y;

	img_rat = (double)scene->resx / scene->resy;
	scrn_x = 2 * (((double)pix.x + 0.5) / scene->resx) - 1;
	scrn_y = 1 - 2 * (((double)pix.y + 0.5) / scene->resy);
	cam_crd.x = scrn_x * img_rat * tan(to_rad(scene->cameras[cam].fov / 2));
	cam_crd.y = scrn_y * tan(to_rad(scene->cameras[cam].fov / 2));
	cam_crd.z = -1;
	return (cam_crd);
}

t_vec3	cam_to_world(t_vec3 cam_crd, t_cam cam)
{
	t_vec3	world_crd;
	t_vec3	rot_vec;
	t_mat33	rot_mat;

	rot_vec = cam.ori;
	rot_mat = mat_rot(rot_vec);
	world_crd = mat_vec(rot_mat, cam_crd);
	world_crd = vec_sous(world_crd, cam.pos);
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
	ray.dir = vec_sum(wrld_crd, ray.start);
	return (ray);
}
