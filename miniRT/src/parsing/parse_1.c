/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:39:16 by fbougama          #+#    #+#             */
/*   Updated: 2020/06/20 13:54:41 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		parse_r(char *line, t_scene *scene_ptr)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	if (scene_ptr->resx > -1)
		return (-1);
	scene_ptr->resx = ft_atoi(line + i);
	ret += skip_int(line, &i);
	ret += skip_whitespaces(line, &i);
	if (line[i] > '9' || line[i] < '0' || ret > 0)
		return (1);
	else
		scene_ptr->resy = ft_atoi(line + i);
	ret += skip_signs(line, &i);
	ret += skip_int(line, &i);
	ret += skip_whitespaces(line, &i);
	if (line[i] || scene_ptr->resx < 1 || scene_ptr->resy < 1)
		return (1);
	scene_ptr->resx = (scene_ptr->resx > RES_MAX_X) ? RES_MAX_X : scene_ptr->resx;
	scene_ptr->resy = (scene_ptr->resy > RES_MAX_Y) ? RES_MAX_Y : scene_ptr->resy;
	return (ret);
}

int		parse_a(char *line, t_scene *scene_ptr)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	if (scene_ptr->amb_light.lum_rat > -1)
		return (-2);
	if ((scene_ptr->amb_light.lum_rat = ft_atof(line + i)) > 1.0)
		return (-3);
	if (scene_ptr->amb_light.lum_rat < 0.0)
		return (-3);
	ret += skip_float(line, &i);
	ret += skip_whitespaces(line, &i);
	if (((line[i] > '9' || line[i] < '0') && line[i] != '-' &&
	line[i] != '+') || ret > 0)
		return (2);
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
		return (-4);
	scene_ptr->cameras[cpt[1]].pos = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->cameras[cpt[1]].ori = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->cameras[cpt[1]].fov = ft_atof(line + i);
	ret += skip_float(line, &i);
	ret += skip_whitespaces(line, &i);
	cpt[1] += 1;
	if (ret > 0 || line[i])
		ret = 3;
	return (ret);
}

int		parse_l(char *line, int cpt[3], t_scene *scene_ptr)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	if (cpt[2] >= MAX_LIGHTS)
		return (-5);
	scene_ptr->lights[cpt[2]].pos = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->lights[cpt[2]].lum_rat = ft_atof(line + i);
	ret += skip_float(line, &i);
	scene_ptr->lights[cpt[2]].color = vec3tocol(ft_atov(line + i));
	cpt[2] += 1;
	ret += skip_vector(line, &i);
	ret += skip_whitespaces(line, &i);
	if (ret > 0 || line[i])
		ret = 4;
	return (ret);
}

int		parse_sp(char *line, int cpt[3], t_scene *scene_ptr)
{
	int	i;
	int	ret;

	ret = 0;
	i = 2;
	if (cpt[0] >= MAX_OBJS)
		return (-6);
	scene_ptr->objects[cpt[0]].type[0] = 's';
	scene_ptr->objects[cpt[0]].type[1] = 'p';
	scene_ptr->objects[cpt[0]].type[2] = '\0';
	scene_ptr->objects[cpt[0]].vec0 = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->objects[cpt[0]].float0 = ft_atof(line + i);
	ret += skip_float(line, &i);
	scene_ptr->objects[cpt[0]].color = vec3tocol(ft_atov(line + i));
	cpt[0] += 1;
	ret += skip_vector(line, &i);
	ret += skip_whitespaces(line, &i);
	if (ret > 0 || line[i])
		ret = 5;
	return (ret);
}
