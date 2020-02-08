/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:32:20 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/08 15:31:31 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vec3	vec(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_mat33	mat_rot_x(t_vec3 rot_vec)
{
	t_mat33	mat_x;

	mat_x.v0 = vec(1, 0, 0);
	mat_x.v1 = vec(0, cos(M_PI * rot_vec.x), sin(M_PI * rot_vec.x));
	mat_x.v2 = vec(0, -sin(M_PI * rot_vec.x), cos(M_PI * rot_vec.x));
	return (mat_x);
}

t_mat33	mat_rot_y(t_vec3 rot_vec)
{
	t_mat33	mat_y;

	mat_y.v0 = vec(cos(M_PI * rot_vec.y), 0, -sin(M_PI * rot_vec.y));
	mat_y.v1 = vec(0, 1, 0);
	mat_y.v2 = vec(sin(M_PI * rot_vec.y), 0, cos(M_PI * rot_vec.y));
	return (mat_y);
}

t_mat33	mat_rot_z(t_vec3 rot_vec)
{
	t_mat33	mat_z;

	mat_z.v0 = vec(cos(M_PI * rot_vec.z), sin(M_PI * rot_vec.z), 0);
	mat_z.v1 = vec(-sin(M_PI * rot_vec.z), cos(M_PI * rot_vec.z), 0);
	mat_z.v2 = vec(0, 0, 1);
	return (mat_z);
}

t_mat33	mat_rot(t_vec3 rot_vec)
{
	t_mat33	mat;

	mat = prod_mat(mat_rot_z(rot_vec), mat_rot_y(rot_vec));
	mat = prod_mat(mat, mat_rot_x(rot_vec));
	return (mat);
}