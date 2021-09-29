/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:14:32 by faysal            #+#    #+#             */
/*   Updated: 2021/09/29 21:30:52 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	p_to_iso(t_point p)
{
	t_point	new;
	double	z_coef;

	z_coef = 0.5;
	new.y = (p.y - p.x) * sqrt(2) / 2;
	new.x = -(sqrt(0.66) * p.z * z_coef - (1 / sqrt(6)) * (p.x + p.y));
	new.z = p.z;
	new.color = p.color;
	new.set = p.set;
	return (new);
}

void	map_to_iso(t_point **map, char *filename, int r_nb)
{
	int	i;
	int	j;
	int	l_l;

	i = 0;
	while (i < r_nb)
	{
		j = 0;
		l_l = line_length(i, filename, r_nb);
		while (j < l_l)
		{
			map[i][j] = p_to_iso(map[i][j]);
			j++;
		}
		i++;
	}
}

void	tab_line_free(char *line, char **split)
{
	free(line);
	free_tab((void **)split);
}

void	get_next_line_protect(int *fd, char **line)
{
	get_next_line(*fd, line);
	while (ft_strlen(*line) == 0)
	{
		free(*line);
		get_next_line(*fd, line);
	}
}
