/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:12:33 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/29 13:20:00 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\r' ||
	c == '\v' || c == '\f' || c == ' ');
}

double	ft_atof(char *str)
{
	int		i;
	double	int_part;
	double	dec_part;
	double	signe;

	i = 0;
	signe = 1.0;
	int_part = (double)ft_atoi(str);
	skip_whitespaces(str, &i);
	if (str[i] == '-')
	{
		signe = -signe;
		i++;
	}
	skip_numbers(str, &i);
	dec_part = 0.0;
	if (str[i] == '.')
	{
		i++;
		dec_part = (double)ft_atoi(str + i);
		while (str[i] && str[i] <= '9' && str[i] >= '0')
		{
			dec_part = dec_part / 10;
			i++;
		}
	}
	return (int_part + signe * dec_part);
}

t_vec3	ft_atov(char *str)
{
	int		i;
	t_vec3	vector;

	i = 0;
	vector.x = ft_atof(str);
	skip_float(str, &i);
	i++;
	vector.y = ft_atof(str + i);
	skip_float(str, &i);
	if (str[i] == ',')
		i++;
	vector.z = ft_atof(str + i);
	return (vector);
}

t_color	vec3tocol(t_vec3 v)
{
	t_color	c;

	c.r = (int)v.x;
	c.g = (int)v.y;
	c.b = (int)v.z;
	return (c);
}

int		skip_whitespaces(char *str, int *i)
{
	while (ft_isspace(str[*i]))
		*i += 1;
	return (0);
}