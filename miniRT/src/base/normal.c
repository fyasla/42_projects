/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:54:22 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/24 11:43:44 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vec3	collision_normal(t_ray ray, t_scene *scene)
{
	double	t;
	t_obj	clst;

	t = collision(ray, clst);
	clst = closest(ray, scene);
	if (clst.type[0] == 's' && clst.type[1] == 'p')
		return (normal_sp(ray, clst));
	else if (clst.type[0] == 'p' && clst.type[1] == 'l')
		return (normal_pl(ray, clst));
	// else if (clst.type[0] == 's' && clst.type[1] == 'q')
	// 	return (normal_sq(ray, clst));
	// else if (clst.type[0] == 'c' && clst.type[1] == 'y')
	// 	return (normal_cy(ray, clst));
	// else if (clst.type[0] == 't' && clst.type[1] == 'r')
	// 	return (normal_tr(ray, clst));
	else
		return (vec(0,0,0));
}

t_vec3	normal_sp(t_ray ray, t_obj clst)
{
	t_vec3	norm;
	t_vec3	hit_pt;
	double	t;

	t = collision(ray, clst);
	hit_pt = vec_sum(ray.start, mul_vec(t, ray.dir));
	norm = normalize_vec(vec_sous(hit_pt, clst.vec0));
	return (norm);
}

t_vec3	normal_pl(t_ray ray, t_obj clst)
{
	return(clst.vec1);
}