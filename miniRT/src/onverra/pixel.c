/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:32:17 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/07 16:05:12 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		pix_col(t_pix pix, t_scene *scene, int cam)
{
	int		i;
	t_ray	ray;

	i = 0;
	ray = pix_ray(pix, scene, cam);
	while (i < MAX_OBJS && scene->objects[i].type[0] != '_')
	{
		if(scene->objects[i].type[0] == 's')
			return (color_to_int(collision(ray, scene->objects[i])));
		i++;
	}
	return (0);
}

t_vec3	rstr_to_cam(t_pix pix, t_scene *scene, int cam)
{
	t_vec3	cam_crd;
	double	img_rat;
	double 	scrn_x;
	double 	scrn_y;


	img_rat = (double)scene->resx / scene->resy;
	scrn_x = 2 * (((double)pix.x + 0.5) / scene->resx) - 1;
	scrn_y = 1 - 2 *(((double)pix.y + 0.5) / scene->resy);
	cam_crd.x = scrn_x * img_rat * tan(to_rad(scene->cameras[cam].fov / 2));
	cam_crd.y = scrn_y * tan(to_rad(scene->cameras[cam].fov / 2));
	cam_crd.z = -1;
	return (cam_crd);
}

t_vec3	cam_to_world(t_vec3 cam_crd, t_cam cam)
{
	t_vec3	world_crd;
	t_vec3	axe;
	t_mat33	mat;

	axe = cam.ori;
	mat = mat_rot(axe);
	world_crd = mat_vec(mat, cam_crd);
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
	// printf("cam_crd : %f, %f, %f\n", cam_crd.x, cam_crd.y, cam_crd.z);
	// printf("wrld_crd : %f, %f, %f\n", wrld_crd.x, wrld_crd.y, wrld_crd.z);
	// printf("ray.start : %f, %f, %f\n", ray.start.x, ray.start.y, ray.start.z);
	// printf("ray.dir : %f, %f, %f\n\n", ray.dir.x, ray.dir.y, ray.dir.z);

	return (ray);
}