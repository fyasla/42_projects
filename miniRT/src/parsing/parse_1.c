/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:39:16 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/21 18:19:18 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_R(char *line, int **cpt_ptr, t_scene *scene_ptr)
{
	int	i;

	i = 1;
	if (scene_ptr->resX > -1)
	{
		write(1, "ERROR\nMultiple resolution specifiers", 50);
		return ;
	}
	while (ft_isspace(str[i]))
		i++;
	if (str[i] > '9' || str[i] < '0')
	{
		write(1, "ERROR\nResolution arguments must be 2 integers", 50);
		return ;
	}
	else
		scene_ptr->resX = ft_atoi(str + i);
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] > '9' || str[i] < '0')
	{
		write(1, "ERROR\nResolution arguments must be 2 integers", 50);
		return ;
	}
	else
		scene_ptr->resY = ft_atoi(str + i);
}