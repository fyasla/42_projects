/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:46:52 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/31 17:13:06 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	scal_prod(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec3	vec_sum(t_vec3 u, t_vec3 v)
{
	t_vec3	sum;

	sum.x = u.x + v.x;
	sum.y = u.y + v.y;
	sum.z = u.z + v.z;
	return (sum);
}

t_vec3	mul_vec(double k, t_vec3 u)
{
	t_vec3	res;

	res.x = k * u.x;
	res.y = k * u.y;
	res.z = k * u.z;
	return (res);
}

double	vec_norme(t_vec3 u)
{
	return (sqrt(u.x * u.x + u.y * u.y + u.z * u.z));
}

t_vec3	normalize_vec(t_vec3 u)
{
	if (vec_norme(u) == 0)
		return (u);
	return (mul_vec((1 / vec_norme(u)), u));
}
