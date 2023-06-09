/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:35:38 by fbougama          #+#    #+#             */
/*   Updated: 2020/03/12 16:21:52 by fbougama         ###   ########.fr       */
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
		return (-6);
	scene_ptr->objects[cpt[0]].type[0] = 'p';
	scene_ptr->objects[cpt[0]].type[1] = 'l';
	scene_ptr->objects[cpt[0]].type[2] = '\0';
	scene_ptr->objects[cpt[0]].vec0 = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->objects[cpt[0]].vec1 = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->objects[cpt[0]].color = vec3tocol(ft_atov(line + i));
	cpt[0] += 1;
	ret += skip_vector(line, &i);
	ret += skip_whitespaces(line, &i);
	if (ret > 0 || line[i])
		ret = 6;
	return (ret);
}

int		parse_sq(char *line, int cpt[3], t_scene *scene_ptr)
{
	int	i;
	int	ret;

	ret = 0;
	i = 2;
	if (cpt[0] >= MAX_OBJS)
		return (-6);
	scene_ptr->objects[cpt[0]].type[0] = 's';
	scene_ptr->objects[cpt[0]].type[1] = 'q';
	scene_ptr->objects[cpt[0]].type[2] = '\0';
	scene_ptr->objects[cpt[0]].vec0 = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->objects[cpt[0]].vec1 = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->objects[cpt[0]].float0 = ft_atof(line + i);
	ret += skip_float(line, &i);
	scene_ptr->objects[cpt[0]].color = vec3tocol(ft_atov(line + i));
	cpt[0] += 1;
	ret += skip_vector(line, &i);
	ret += skip_whitespaces(line, &i);
	if (ret > 0 || line[i])
		ret = 7;
	return (ret);
}

int		parse_cy(char *line, int cpt[3], t_scene *scene_ptr)
{
	int	i;
	int	ret;

	ret = 0;
	i = 2;
	if (cpt[0] >= MAX_OBJS)
		return (-6);
	scene_ptr->objects[cpt[0]].type[0] = 'c';
	scene_ptr->objects[cpt[0]].type[1] = 'y';
	scene_ptr->objects[cpt[0]].type[2] = '\0';
	scene_ptr->objects[cpt[0]].vec0 = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->objects[cpt[0]].vec1 = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->objects[cpt[0]].float0 = ft_atof(line + i);
	ret += skip_float(line, &i);
	scene_ptr->objects[cpt[0]].float1 = ft_atof(line + i);
	ret += skip_float(line, &i);
	scene_ptr->objects[cpt[0]].color = vec3tocol(ft_atov(line + i));
	cpt[0] += 1;
	ret += skip_vector(line, &i);
	ret += skip_whitespaces(line, &i);
	if (ret > 0 || line[i])
		ret = 8;
	return (ret);
}

int		parse_tr(char *line, int cpt[3], t_scene *scene_ptr)
{
	int	i;
	int	ret;

	ret = 0;
	i = 2;
	if (cpt[0] >= MAX_OBJS)
		return (-6);
	scene_ptr->objects[cpt[0]].type[0] = 't';
	scene_ptr->objects[cpt[0]].type[1] = 'r';
	scene_ptr->objects[cpt[0]].type[2] = '\0';
	scene_ptr->objects[cpt[0]].vec0 = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->objects[cpt[0]].vec1 = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->objects[cpt[0]].vec2 = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->objects[cpt[0]].color = vec3tocol(ft_atov(line + i));
	cpt[0] += 1;
	ret += skip_vector(line, &i);
	ret += skip_whitespaces(line, &i);
	if (ret > 0 || line[i])
		ret = 9;
	return (ret);
}
