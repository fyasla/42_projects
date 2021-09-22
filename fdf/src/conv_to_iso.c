/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:14:32 by faysal            #+#    #+#             */
/*   Updated: 2021/09/22 16:25:41 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	p_to_iso(t_point p)
{
	t_point	new;
	double	z_coef;

	z_coef = 1;
	new.y = (p.y - p.x) * sqrt(2) / 2;
	new.x = -(sqrt(0.66) * p.z * z_coef - (1 / sqrt(6)) * (p.x + p.y));
	return (new);
}

void	map_to_iso(t_point ***map, int row_nb, int col_nb)
{
	int	i;
	int	j;

	i = 0;
	while (i < row_nb)
	{
		j = 0;
		while (j < col_nb)
		{
			*map[i][j] = p_to_iso(*map[i][j]);
			j++;
		}
		i++;
	}
}
