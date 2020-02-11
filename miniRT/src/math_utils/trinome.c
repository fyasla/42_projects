/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trinome.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:27:57 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/11 13:46:36 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	discriminant(t_vec3 tri)
{
	return(tri.y * tri.y - 4 * tri.x * tri.z);
}

int		nb_pos_sol(t_vec3 tri)
{
	int		nb;
	double	sol;
	double delta;

	nb = 0;
	delta = discriminant(tri);
	if (delta < 0)
		return (0);
	sol = (-tri.y - sqrt(delta)) / (2 * tri.x);
	if (sol >= 0)
		nb += 1;
	sol = (-tri.y + sqrt(delta)) / (2 * tri.x);
	if (sol >= 0)
		nb += 1;
	return (nb);
}

double	smallest_sol(t_vec3 tri)
{
	double	sol;
	double delta;

	delta = discriminant(tri);
	if (delta < 0)
		return (-1);
	sol = (-tri.y - sqrt(delta)) / (2 * tri.x);
	if (sol >= 0)
		return (sol);
	sol = (-tri.y + sqrt(delta)) / (2 * tri.x);
	if (sol >= 0)
		return (sol);
	else
		return (-1);
}

double	biggest_sol(t_vec3 tri)
{
	double	sol;
	double delta;

	delta = discriminant(tri);
	if (delta < 0)
		return (-1);
	sol = (-tri.y + sqrt(delta)) / (2 * tri.x);
	if (sol >= 0)
		return (sol);
	else
		return (-1);
}