/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:35:38 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/31 16:36:45 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		parse_pl(char *line, int cpt[3], t_scene *scene_ptr)
{
	int	i;
	int	ret;

	ret = 0;
	i = 2;
	if (cpt[0] >= MAX_OBJS)
		return (-1);
	scene_ptr->objects[cpt[0]].type[0] = 'p';
	scene_ptr->objects[cpt[0]].type[1] = 'l';
	scene_ptr->objects[cpt[0]].type[2] = '\0';
	scene_ptr->objects[cpt[0]].vec0 = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->objects[cpt[0]].vec1 = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->objects[cpt[0]].color = vec3tocol(ft_atov(line + i));
	cpt[0] += 1;
	return(ret);
}