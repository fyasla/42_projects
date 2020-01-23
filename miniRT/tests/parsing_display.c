/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:02:33 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/23 15:17:21 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	ft_printfloat(double x)
{
	int		dec_part;

	dec_part = (int)((x - (int)x) * 1000000);
	ft_printf("%d.", (int)x);
	ft_printf("%d", dec_part);
}
void	display_obj(t_obj object)
{
	ft_printf("type : %s\n", object.type);
	ft_printf("vec0: %d, %d, %d\n", (int)object.vec0.x, (int)object.vec0.y, (int)object.vec0.z);
	ft_printf("vec1: %d, %d, %d\n", (int)object.vec1.x, (int)object.vec1.y, (int)object.vec1.z);
	ft_printf("vec2: %d, %d, %d\n", (int)object.vec2.x, (int)object.vec2.y, (int)object.vec2.z);
	ft_printf("float0 : %s\n", (int)object.float0);
	ft_printf("float1 : %s\n", (int)object.float1);
}