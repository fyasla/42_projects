/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:05:31 by fbougama          #+#    #+#             */
/*   Updated: 2019/07/23 12:36:27 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_solution.h"

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int		ft_length(int **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return(i);
}

int		ft_height(int **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}


int		**ft_copy(int **map)
{
	int i;
	int j;
	int **cpy;
	int	height;
	int	length;

	i = 0;
	height = ft_height(map);
	length = ft_length(map);
	cpy = malloc((height + 1) * sizeof(*cpy));
	while (i < height)
	{
		j = 0;
		while (j < length)
		{
			cpy[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (cpy);
}


t_solution	ft_solve(int **map)
{
	int			i;
	int			j;
	int			**cpy;
	t_solution	sol;
	int	height;
	int	length;

	height = ft_height(map);
	length = ft_length(map);
	cpy = ft_copy(map);
	i = 0;
	sol.size = 0;
	while (i < height)
	{
		j = 0;
		while (j < length)
		{
			if (i > 0 && j > 0)
				cpy[i][j] = ft_min(ft_min(cpy[i - 1][j - 1], cpy[i][j - 1]), cpy[i - 1][j]);
			if (cpy[i][j] > sol.size)
			{
				sol.x = i;
				sol.y = j;
				sol.size = cpy[i][j];
			}
			j++;
		}
		i++;
	}
	return (sol);
}

