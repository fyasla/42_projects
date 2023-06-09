/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:08:57 by fbougama          #+#    #+#             */
/*   Updated: 2020/03/02 11:35:26 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	collision(t_ray ray, t_obj object)
{
	if (object.type[0] == 's' && object.type[1] == 'p')
		return (collision_sp(ray, object));
	else if (object.type[0] == 'p' && object.type[1] == 'l')
		return (collision_pl(ray, object));
	else if (object.type[0] == 's' && object.type[1] == 'q')
		return (collision_sq(ray, object));
	else if (object.type[0] == 'c' && object.type[1] == 'y')
		return (collision_cy(ray, object));
	else if (object.type[0] == 't' && object.type[1] == 'r')
		return (collision_tr(ray, object));
	else
		return (-1);
}

t_obj	closest(t_ray ray, t_scene *scene)
{
	int		i;
	double	dist;
	t_obj	closest;
	double	t;

	i = 0;
	dist = -1;
	while (i < MAX_OBJS && scene->objects[i].type[0] != '_')
	{
		t = collision(ray, scene->objects[i]);
		if (t > 0 &&
		(t < dist || dist == -1))
		{
			closest = scene->objects[i];
			dist = t;
		}
		i++;
	}
	if (dist == -1)
		initiate_obj(&closest);
	return (closest);
}

double	collision_sp(t_ray ray, t_obj sphere)
{
	double	t;
	t_vec3	tri;
	t_vec3	tmp;

	t = -1;
	tri.x = scal_prod(ray.dir, ray.dir);
	tri.y = 2 * scal_prod(ray.dir, vec_sous(ray.start, sphere.vec0));
	tmp = vec_sous(ray.start, sphere.vec0);
	tri.z = scal_prod(tmp, tmp) - (sphere.float0 * sphere.float0 / 4);
	t = smallest_sol(tri);
	return (t);
}

double	collision_pl(t_ray ray, t_obj plane)
{
	double	t;

	if (scal_prod(ray.dir, plane.vec1) == 0)
		return (-1);
	t = scal_prod(plane.vec0, plane.vec1);
	t -= scal_prod(ray.start, plane.vec1);
	t = t / (scal_prod(ray.dir, plane.vec1));
	if (t >= 0)
		return (t);
	return (-1);
}

double	collision_sq(t_ray ray, t_obj square)
{
	double	t;
	t_vec3	norm;
	t_vec3	pt;

	norm = mat_vec(mat_rot(square.vec1), vec(0, 0, 1));
	if (scal_prod(ray.dir, norm) == 0)
		return (-1);
	t = scal_prod(square.vec0, norm);
	t -= scal_prod(ray.start, norm);
	t = t / (scal_prod(ray.dir, norm));
	if (t <= 0)
		return (-1);
	pt = vec_sum(ray.start, mul_vec(t, ray.dir));
	pt = vec_sous(pt, square.vec0);
	norm = vec(0, 1, 0);
	norm = mat_vec(mat_rot(square.vec1), norm);
	if (scal_prod(pt, norm) *
	scal_prod(pt, norm) > square.float0 * square.float0 / 4)
		return (-1);
	norm = mat_vec(mat_rot(square.vec1), vec(1, 0, 0));
	if (scal_prod(pt, norm) *
	scal_prod(pt, norm) > square.float0 * square.float0 / 4)
		return (-1);
	return (t);
	return (-1);
}
