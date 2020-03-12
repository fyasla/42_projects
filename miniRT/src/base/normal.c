/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:54:22 by fbougama          #+#    #+#             */
/*   Updated: 2020/03/12 17:09:29 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vec3	collision_normal(t_ray ray, t_scene *scene)
{
	if (ray.clst.type[0] == 's' && ray.clst.type[1] == 'p')
		return (normal_sp(ray, ray.clst));
	else if (ray.clst.type[0] == 'p' && ray.clst.type[1] == 'l')
		return (ray.clst.vec1);
	else if (ray.clst.type[0] == 's' && ray.clst.type[1] == 'q')
		return (normal_sq(ray, ray.clst));
	else if (ray.clst.type[0] == 'c' && ray.clst.type[1] == 'y')
		return (normal_cy(ray, ray.clst));
	else if (ray.clst.type[0] == 't' && ray.clst.type[1] == 'r')
		return (normal_tr(ray, ray.clst));
	else
		return (vec(0, 0, 0));
}

t_vec3	normal_sp(t_ray ray, t_obj sp)
{
	t_vec3	norm;
	t_vec3	hit_pt;

	hit_pt = vec_sum(ray.start, mul_vec(ray.t, ray.dir));
	norm = normalize_vec(vec_sous(hit_pt, sp.vec0));
	return (norm);
}

t_vec3	normal_sq(t_ray ray, t_obj sq)
{
	t_vec3	norm;
	t_mat33	rot;

	rot = mat_rot(sq.vec1);
	norm = mat_vec(rot, vec(0, 0, 1));
	return (norm);
}

t_vec3	normal_cy(t_ray ray, t_obj cy)
{
	t_vec3	hit_pt;
	t_vec3	norm;
	t_vec3	axe;
	t_vec3	v1n;

	hit_pt = vec_sum(ray.start, mul_vec(ray.t, ray.dir));
	norm = vec_sous(hit_pt, cy.vec0);
	v1n = normalize_vec(cy.vec1);
	axe = mul_vec(fabs(scal_prod(norm, v1n)), v1n);
	if (scal_prod(norm, cy.vec1) < 0)
		axe = mul_vec(-1, axe);
	norm = vec_sous(norm, axe);
	norm = normalize_vec(norm);
	return (norm);
}

t_vec3	normal_tr(t_ray ray, t_obj tr)
{
	t_vec3	side0;
	t_vec3	side1;
	t_vec3	norm;

	side0 = vec_sous(tr.vec1, tr.vec0);
	side1 = vec_sous(tr.vec2, tr.vec0);
	norm = vec_prod(side0, side1);
	norm = normalize_vec(norm);
	return (norm);
}
