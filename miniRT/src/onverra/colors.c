/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:03:54 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/19 18:19:52 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_color		obj_illum(t_color col, t_light light)
{
	t_color		res;

	res.r = (unsigned int)((double)col.r * light.lum_rat * (double)light.color.r / 255);
	res.g = (unsigned int)((double)col.g * light.lum_rat * (double)light.color.g / 255);
	res.b = (unsigned int)((double)col.b * light.lum_rat * (double)light.color.b / 255);
	return (res);
}

t_light		total_light(t_vec3 pos, t_scene *scene)
{
	t_ray	ray;
	t_light	sum;
	int		i;
	int		j;

	initiate_light(&sum);
	ray.start = pos;
	i = 0;
	while (i < scene->cpt[2])
	{
		j = 0;
		ray.dir = (vec_sous(scene->lights[i].pos, pos));
		while (j < scene->cpt[0])
		{
			if (collision(ray, scene->objects[j]) >= 0)
			{
				j = scene->cpt[0];
			}
			j++;
		}
		 if (j == scene->cpt[0])
		 	sum = light_sum(sum, scene->lights[i]);
		i++;
	}
	sum = light_sum(sum, scene->amb_light);
	return (sum);
}

t_light		light_sum(t_light l1, t_light l2)
{
	t_light	sum;

	sum.color.r = (unsigned int)fmin((l1.lum_rat * (double)l1.color.r + l2.lum_rat * (double)l2.color.r), 255);
	sum.color.g = (unsigned int)fmin((l1.lum_rat * (double)l1.color.g + l2.lum_rat * (double)l2.color.g), 255);
	sum.color.b = (unsigned int)fmin((l1.lum_rat * (double)l1.color.b + l2.lum_rat * (double)l2.color.b), 255);
	sum.lum_rat = 1;
	return (sum);
}