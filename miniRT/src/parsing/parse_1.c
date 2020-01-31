/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:39:16 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/31 18:24:30 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		parse_r(char *line, t_scene *scene_ptr)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	if (scene_ptr->resX > -1)
		return (-1);
	scene_ptr->resX = ft_atoi(line + i);
	ret += skip_int(line, &i);
	ret += skip_whitespaces(line, &i);
	ret += skip_signs(line, &i);
	if (line[i] > '9' || line[i] < '0')
		write(1, "ERROR\nResolution arguments must be 2 integers\n", 59);
	else
		scene_ptr->resY = ft_atoi(line + i);
	return (ret);
}

int		parse_a(char *line, t_scene *scene_ptr)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	if (scene_ptr->amb_light.lum_rat > -1)
		return (-1);
	if ((scene_ptr->amb_light.lum_rat = ft_atof(line + i)) > 1.0)
		return (-1);
	ret += skip_float(line, &i);
	ret += skip_whitespaces(line, &i);
	if ((line[i] > '9' || line[i] < '0') && line[i] != '-' && line[i] != '+')
		return (-1);
	else
		scene_ptr->amb_light.color = vec3tocol(ft_atov(line + i));
	return (ret);
}

int		parse_c(char *line, int cpt[3], t_scene *scene_ptr)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	if (cpt[1] >= MAX_CAMS)
		return (-1);
	scene_ptr->cameras[cpt[1]].pos = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->cameras[cpt[1]].ori = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->cameras[cpt[1]].fov = ft_atof(line + i);
	cpt[1] += 1;
	return (ret);
}

int		parse_l(char *line, int cpt[3], t_scene *scene_ptr)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	if (cpt[2] >= MAX_LIGHTS)
		return (-1);
	scene_ptr->lights[cpt[2]].pos = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->lights[cpt[2]].lum_rat = ft_atof(line + i);
	ret += skip_float(line, &i);
	scene_ptr->lights[cpt[2]].color = vec3tocol(ft_atov(line + i));
	cpt[2] += 1;
	return (ret);
}

int		parse_sp(char *line, int cpt[3], t_scene *scene_ptr)
{
	int	i;
	int	ret;

	ret = 0;
	i = 2;
	if (cpt[0] >= MAX_OBJS)
		return (-1);
	scene_ptr->objects[cpt[0]].type[0] = 's';
	scene_ptr->objects[cpt[0]].type[1] = 'p';
	scene_ptr->objects[cpt[0]].type[2] = '\0';
	scene_ptr->objects[cpt[0]].vec0 = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->objects[cpt[0]].float0 = ft_atof(line + i);
	ret += skip_float(line, &i);
	scene_ptr->objects[cpt[0]].color = vec3tocol(ft_atov(line + i));
	cpt[0] += 1;
	return (ret);
}
