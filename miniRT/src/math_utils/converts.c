/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:54:23 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/05 14:38:12 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vec3	mat_vec(t_mat33 mat, t_vec3 vec)
{
	t_vec3	res;

	res.x = mat33.v0.x * vec.x + mat33.v1.x * vec.y + mat33.v2.x * vec.z;
	res.y = mat33.v0.y * vec.x + mat33.v1.y * vec.y + mat33.v2.y * vec.z;
	res.y = mat33.v0.z * vec.x + mat33.v1.z * vec.y + mat33.v2.z * vec.z;
	return (res);
}

t_mat33	prod_mat(t_mat33 a, t_mat33 b)
{
	t_mat33	prod;

	prod.v0 = mat_vec(a, b.v0);
	prod.v1 = mat_vec(a, b.v1);
	prod.v2 = mat_vec(a, b.v2);
}

double	to_rad(double deg)
{
	return (deg * M_PI / 180);
}
