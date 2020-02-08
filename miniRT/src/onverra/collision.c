/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:08:57 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/08 16:30:31 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	collision(t_ray ray, t_obj object)
{
	double	t;
	t_vec3	tri;

	t = -1;
	if(object.type[0] != 's' || object.type[1] != 'p')
		return (0);
	tri.x = scal_prod(ray.dir, ray.dir);
	tri.y = 2 * scal_prod(ray.dir, vec_sous(ray.start, object.vec0));
	tri.z = scal_prod(vec_sous(ray.start, object.vec0), vec_sous(ray.start, object.vec0)) - (object.float0 * object.float0 / 4);
	t = smallest_sol(tri);
	return (t);
}

t_obj	closest(t_ray ray, t_scene *scene)
{
	int		i;
	double	dist;
	t_obj	closest;

	i = 0;
	dist = -1;
	while (i < MAX_OBJS && scene->objects[i].type[0] != '_')
	{
		if (collision(ray, scene->objects[i]) > 0 && (collision(ray, scene->objects[i]) < dist || dist == -1))
		{
			closest = scene->objects[i];
			dist = collision(ray, scene->objects[i]);
		}
		i ++;
	}
	if (dist == -1)
		closest.type[0] = '_';
	return (closest);
}