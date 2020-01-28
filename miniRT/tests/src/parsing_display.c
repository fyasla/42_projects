/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:02:33 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/23 17:28:19 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_printfloat(double x)
{
	int		dec_part;

	dec_part = (int)((x - (int)x) * 1000000);
	dec_part = (x < 0) ? -dec_part : dec_part;
	ft_printf("%d.", (int)x);
	ft_printf("%d", dec_part);
}

void	display_vec3(t_vec3 v)
{
	ft_printf("(");
	ft_printfloat(v.x);
	ft_printf(", ");
	ft_printfloat(v.y);
	ft_printf(", ");
	ft_printfloat(v.z);
	ft_printf(")");
}

void	display_obj(t_obj object)
{
	ft_printf("type : %s\n", object.type);
	ft_printf("vec0: ");
	display_vec3(object.vec0);
	ft_printf("\n");
	ft_printf("vec0: ");
	display_vec3(object.vec1);
	ft_printf("\n");
	ft_printf("vec0: ");
	display_vec3(object.vec2);
	ft_printf("\n");
	ft_printf("float0: ");
	ft_printfloat(object.float0);
	ft_printf("\n");
	ft_printf("float1: ");
	ft_printfloat(object.float1);
	ft_printf("\n");
}

void	display_cam(t_cam camera)
{
	ft_printf("Position: ");
	display_vec3(camera.pos);
	ft_printf("\n");
	ft_printf("Orientation: ");
	display_vec3(camera.ori);
	ft_printf("\n");
	ft_printf("FOV: ");
	ft_printfloat(camera.fov);
	ft_printf("\n");
}