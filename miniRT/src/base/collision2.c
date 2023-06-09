/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:23:29 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/21 16:30:47 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	collision_cy(t_ray ray, t_obj cyl)
{
	double	t;
	t_vec3	tri;
	t_vec3	pt;
	t_vec3	ori;

	ori = normalize_vec(cyl.vec1);
	tri.x = cyl_tri_2(ray, cyl);
	tri.y = cyl_tri_1(ray, cyl);
	tri.z = cyl_tri_0(ray, cyl);
	t = smallest_sol(tri);
	pt = vec_sum(ray.start, mul_vec(t, ray.dir));
	if (fabs(scal_prod(pt, ori)) > cyl.float1)
	{
		t = biggest_sol(tri);
		pt = vec_sum(ray.start, mul_vec(t, ray.dir));
		if (fabs(scal_prod(pt, ori)) > cyl.float1)
			return (-1);
	}
	return (t);
}

double	cyl_tri_2(t_ray ray, t_obj cyl)
{
	double	coef;
	t_vec3	ori;

	ori = normalize_vec(cyl.vec1);
	coef = scal_prod(ray.dir, ray.dir);
	coef = coef - scal_prod(ray.dir, ori) * scal_prod(ray.dir, ori);
	return (coef);
}

double	cyl_tri_1(t_ray ray, t_obj cyl)
{
	double	coef;
	t_vec3	ori;
	t_vec3	c;

	c = cyl.vec0;
	ori = normalize_vec(cyl.vec1);
	coef = 2 * (scal_prod(ray.dir, vec_sous(ray.start, c)));
	coef -= 2 * (scal_prod(ray.dir, ori) *
	scal_prod(vec_sous(ray.start, c), ori));
	return (coef);
}

double	cyl_tri_0(t_ray ray, t_obj cyl)
{
	double	coef;
	t_vec3	ori;
	t_vec3	c;

	c = cyl.vec0;
	ori = normalize_vec(cyl.vec1);
	coef = -scal_prod(vec_sous(ray.start, c), ori);
	coef *= scal_prod(vec_sous(ray.start, c), ori);
	coef += scal_prod(vec_sous(ray.start, c), vec_sous(ray.start, c));
	coef -= cyl.float0 * cyl.float0 / 4;
	return (coef);
}
