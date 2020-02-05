/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:08:57 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/05 15:23:39 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_col	collision(t_ray ray, t_obj object)
{
	t_col	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	if(object.type[0] != 's' || object.type[1] != 'p')
		return (color);
	
}