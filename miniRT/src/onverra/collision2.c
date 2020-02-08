/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:23:29 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/08 20:12:51 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	collision_cy(t_ray ray, t_obj cyl)
{
	double	t;
	t_vec3	dir;
	t_vec3	tri;
	t_vec3	pt;

	dir = normalize_vec(cyl.vec1);
	tri.x = cyl_tri_2(ray, cyl);
	tri.y = cyl_tri_1(ray, cyl);
	tri.z = cyl_tri_0(ray, cyl);
	t = smallest_sol(tri);
	pt = vec_sum(ray.start, mul_vec(t, ray.dir));
	// if (scal_prod(vec_sous(pt, cyl.vec0), vec_sous(pt, cyl.vec0)) > (cyl.float1 * cyl.float1 + cyl.float0 * cyl.float0) / 4)
	// 	return (-1);
	return (t);
}

double	cyl_tri_2(t_ray ray, t_obj cyl)
{
	double	coef;
	t_vec3	dir;

	dir = normalize_vec(cyl.vec1);
	coef = scal_prod(ray.dir, ray.dir);
	coef = coef - scal_prod(ray.dir, dir) * scal_prod(ray.dir, dir);
	return (coef);
}

double	cyl_tri_1(t_ray ray, t_obj cyl)
{
	double	coef;
	t_vec3	dir;
	t_vec3	c;

	c = cyl.vec0;
	dir = normalize_vec(cyl.vec1);
	coef = 2 * (scal_prod(ray.dir, vec_sous(ray.start, c)));
	coef -= 2 * (scal_prod(ray.dir, dir) * scal_prod(vec_sous(ray.start, c), dir));
	return (coef);
}

double cyl_tri_0(t_ray ray, t_obj cyl)
{
	double	coef;
	t_vec3	dir;
	t_vec3	c;

	c = cyl.vec0;
	dir = normalize_vec(cyl.vec1);
	coef = scal_prod(vec_sous(ray.start, c), dir);
	coef *= scal_prod(vec_sous(ray.start, c), dir);
	coef += scal_prod(vec_sous(ray.start, c), vec_sous(ray.start, c));
	coef -= cyl.float0 * cyl.float0 / 4;
	return (coef);
}