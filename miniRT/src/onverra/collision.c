/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:08:57 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/05 16:38:35 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_color	collision(t_ray ray, t_obj object)
{
	t_color	color;
	t_vec3	tri;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	if(object.type[0] != 's' || object.type[1] != 'p')
		return (color);
	tri.x = scal_prod(ray.dir, ray.dir);
	tri.y = 2 * scal_prod(ray.dir, vec_sous(ray.start, object.vec0));
	tri.z = scal_prod(vec_sous(ray.start, object.vec0), vec_sous(ray.start, object.vec0)) - 1;
	if (nb_pos_sol(tri) >= 0)
		color.r = 255;
	return (color);
}