/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:43:19 by fbougama          #+#    #+#             */
/*   Updated: 2020/05/12 22:32:53 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	initiate_obj(t_obj *object)
{
	object->type[0] = '_';
	object->type[1] = '_';
	object->type[2] = '\0';
	object->vec0.x = 0.0;
	object->vec0.y = 0.0;
	object->vec0.z = 0.0;
	object->vec1.x = 0.0;
	object->vec1.y = 0.0;
	object->vec1.z = 0.0;
	object->vec2.x = 0.0;
	object->vec2.y = 0.0;
	object->vec2.z = 0.0;
	object->color.r = 0;
	object->color.g = 0;
	object->color.b = 0;
	object->float0 = 0.0;
	object->float1 = 0.0;
}

void	initiate_cam(t_cam *camera)
{
	camera->pos.x = 0.0;
	camera->pos.y = 0.0;
	camera->pos.z = 0.0;
	camera->ori.x = 0.0;
	camera->ori.y = 0.0;
	camera->ori.z = 0.0;
	camera->fov = 0.0;
}

void	initiate_light(t_light *light)
{
	light->pos.x = 0.0;
	light->pos.y = 0.0;
	light->pos.z = 0.0;
	light->color.r = 0;
	light->color.g = 0;
	light->color.b = 0;
	light->lum_rat = 0.0;
}

void	scene_initiate(t_scene *scene_ptr)
{
	int		i;

	i = 0;
	scene_ptr->cam = 0;
	scene_ptr->resx = -1;
	scene_ptr->resy = -1;
	scene_ptr->amb_light.lum_rat = -1;
	while (i < MAX_OBJS)
		initiate_obj(&scene_ptr->objects[i++]);
	i = 0;
	while (i < MAX_CAMS)
		initiate_cam(&scene_ptr->cameras[i++]);
	i = 0;
	while (i < MAX_LIGHTS)
		initiate_light(&scene_ptr->lights[i++]);
}
