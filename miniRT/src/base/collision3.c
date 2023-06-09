/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:53:36 by fbougama          #+#    #+#             */
/*   Updated: 2020/05/12 22:21:23 by faysal           ###   ########.fr       */
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
	if ((check_tr_som(pt, tr, 0) + check_tr_som(pt, tr, 1) +
	check_tr_som(pt, tr, 2)) < 2)
		return (-1);
	return (t);
}

int		check_tr_som(t_vec3 pt, t_obj tr, int s)
{
	t_vec3	a;
	t_vec3	b;
	t_vec3	c;
	t_vec3	tmp;

	a = tr.vec0;
	b = tr.vec1;
	c = tr.vec2;
	if (s == 1)
	{
		a = tr.vec1;
		b = tr.vec0;
	}
	if (s == 2)
	{
		a = tr.vec2;
		b = tr.vec1;
	}
	pt = vec_sous(pt, a);
	tmp = vec_prod(vec_sous(b, a), pt);
	if (scal_prod(tmp, vec_prod(pt, vec_sous(c, a))) <= 0)
		return (0);
	else
		return (1);
}
