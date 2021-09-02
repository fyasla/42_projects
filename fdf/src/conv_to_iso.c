/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:14:32 by faysal            #+#    #+#             */
/*   Updated: 2021/09/02 11:23:33 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	p_to_iso(t_point p)
{
	t_point	new;

	new.x = p.y - p.x;
	new.y = p.z - p.x - p.y;
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
