/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:39:16 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/22 16:04:01 by fbougama         ###   ########.fr       */
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
	{
		write(1, "ERROR\nMultiple resolution specifiers\n", 59);
		return (-1);
	}
	scene_ptr->resX = ft_atoi(line + i);
	ret += skip_int(line, &i);
	ret += skip_whitespaces(line, &i);
	ret += skip_signs(line, &i);
	if (line[i] > '9' || line[i] < '0')
	{
		write(1, "ERROR\nResolution arguments must be 2 integers\n", 59);
		return (-1);
	}
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
	{
		write(1, "ERROR\nMultiple ambiant light specifiers\n", 60);
		return (-1);
	}
	if ((scene_ptr->amb_light.lum_rat = ft_atof(line + i)) > 1)
	{
		write(1, "ERROR\nAmbiant light intensity \
		argument must be at most 1\n", 57);
		return (-1);
	}
	ret += skip_whitespaces(line, &i);
	ret += skip_numbers(line, &i);
	ret += skip_whitespaces(line, &i);
	if (line[i] > '9' || line[i] < '0')
	{
		write(1, "ERROR\nAmbiant light arguments must \
		be 1 float and one RGB color\n", 64);
		return (-1);
	}
	else
		scene_ptr->amb_light.color = vec3tocol(ft_atov(line + i));
	return (ret);
}

int		parse_c(char *line, int *cpt, t_scene *scene_ptr)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	if (cpt[1] >= MAX_CAMS)
	{
		write(1,"ERROR\nThe scene can't have more than MAX_CAMS cameras\n", 100);
		return (-1);
	}
	return(0);
	scene_ptr->cameras[cpt[1]].pos = ft_atov(line + i);
	ret += skip_vector(line, &i);
	scene_ptr->cameras[cpt[1]].ori = ft_atov(line + i);
	ret += skip_vector(line, &i);
	
}