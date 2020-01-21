/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:39:16 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/21 19:07:56 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		parse_r(char *line, t_scene *scene_ptr)
{
	int	i;

	i = 1;
	if (scene_ptr->resX > -1)
	{
		write(1, "ERROR\nMultiple resolution specifiers", 50);
		return (-1);
	}
	while (ft_isspace(str[i]))
		i++;
	scene_ptr->resX = ft_atoi(str + i);
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] > '9' || str[i] < '0')
	{
		write(1, "ERROR\nResolution arguments must be 2 integers", 50);
		return (-1);
	}
	else
		scene_ptr->resY = ft_atoi(str + i);
	return (0);
}

int		parse_a(char *line, t_scene *scene_ptr)
{
	int	i;

	i = 1;
	if (scene_ptr->amb_light.lum_rat > -1)
	{
		write(1, "ERROR\nMultiple ambiant light specifiers", 50);
		return (-1);
	}
	while (ft_isspace(str[i]))
		i++;
	if ((scene_ptr->amb_light.lum_rat = ft_atof(str + i)) > 1)
	{
		write(1, "ERROR\nAmbiant light intensity \
		argument must be at most 1", 56);
		return (-1);
	}
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] > '9' || str[i] < '0')
	{
		write(1, "ERROR\nAmbiant light arguments must \
		be 1 float and one RGB color", 63);
		return (-1);
	}
	else
		scene_ptr->amb_light.colr = vec3tocol(ft_atoiv(str + i));
	return (0);
}
