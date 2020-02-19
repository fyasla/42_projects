/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:03:54 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/19 16:08:01 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_color		obj_illum(t_color col, t_light light)
{
	t_color		res;

	res.r = (int)((double)col.r * light.lum_rat * (double)light.color.r / 255);
	res.g = (int)((double)col.g * light.lum_rat * (double)light.color.g / 255);
	res.b = (int)((double)col.b * light.lum_rat * (double)light.color.b / 255);
	return (res);
}