/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:12:54 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/24 16:53:22 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vec3	vec_prod(t_vec3 u, t_vec3 v)
{
	t_vec3	prod;

	prod.x = u.y * v.z - u.z * v.y;
	prod.y = u.z * v.x - u.x * v.z;
	prod.z = u.x * v.y - u.y * v.x;
	return (prod);
}

double	distance(t_vec3	a, t_vec3 b)
{
	return (vec_norme(vec_sous(b,a)));
}