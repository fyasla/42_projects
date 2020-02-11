/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:53:36 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/11 14:51:33 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	collision_tr(t_ray ray, t_obj tr)
{
	t_vec3	norm;
	t_vec3	pt;
	double	t;

	norm = vec_prod(vec_sous(tr.vec1, tr.vec0), vec_sous(tr.vec2, tr.vec0));
	if (scal_prod(ray.dir, norm) == 0)
		return (-1);
	t = scal_prod(tr.vec0, norm);
	t -= scal_prod(ray.start, norm);
	t = t / (scal_prod(ray.dir, norm));
	if (t < 0)
		return (-1);
	pt = vec_sum(ray.start, mul_vec(t, ray.dir));
	pt = vec_sous(pt, tr.vec0);
	// if (scal_prod(pt, vec_sous(tr.vec1, tr.vec0)) < 0 ||
	// scal_prod(pt, vec_sous(tr.vec1, tr.vec0)) > 2 * vec_norme(vec_sous(tr.vec1, tr.vec0)) ||
	// scal_prod(pt, vec_sous(tr.vec2, tr.vec0)) < 0 ||
	// scal_prod(pt, vec_sous(tr.vec2, tr.vec0)) > 2 * vec_norme(vec_sous(tr.vec2, tr.vec0)))
	// 	return (-1);
	return (t);
}