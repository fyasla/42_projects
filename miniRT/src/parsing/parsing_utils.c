/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:12:33 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/22 15:01:20 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\r' ||
	c == '\v' || c == '\f' || c == ' ')
}

double	ft_atof(char *str)
{
	int		i;
	double	int_part;
	double	dec_part;
	int		signe;

	i = 0;
	signe = 1;
	int_part = (double)ft_atoi(str);
	skip_whitspaces(str, &i);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	skip_numbers(str, &i);
	if (str[i] == '.')
		i++;
	dec_part = (double)ft_atoi(str + i);
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		dec_part = dec_part / 10;
		i++;
	}
	return (int_part + signe * dec_part);
}

t_vec3	ft_atov(char *str)
{
	int		i;
	t_vec3	vector;

	i = 0;
	vector.x = ft_atof(str);
	while (str[i] != ',')
		i++;
	i++;
	vector.y = ft_atof(str + i);
	while (str[i] != ',')
		i++;
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

void	skip_whitspaces(char *str, int *i)
{
	while (ft_isspace(str[*i]))
		*i++;
}