/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:46:19 by faysal            #+#    #+#             */
/*   Updated: 2021/09/29 00:34:32 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	fill_map(t_point **map, char *filename)
{
	int		i;
	int		j;
	char	*line;
	int		fd;
	char	**split;
	int		ret;

	fd = open(filename, O_RDONLY);
	i = 0;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		j = 0;
		split = ft_split(line, ' ');
		while (split[j] != NULL)
		{	
			map[i][j] = coord(i, j, ft_atoi(split[j]));
			j++;
		}
		map[i][j].set = 0;
		free(line);
		ret = get_next_line(fd, &line);
		free_tab((void **)split);
		i++;
	}
	j = 0;
	split = ft_split(line, ' ');
	while (split[j] != NULL)
	{	
		map[i][j] = coord(i, j, ft_atoi(split[j]));
		j++;
	}
	i++;
	map[i] = NULL;
	free(line);
	free_tab((void **)split);
	close(fd);
}

void	set_color_map(t_point **map, char *filename)
{
	int	i;
	int	j;
	int	r_nb;

	r_nb = row_nb(filename);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j].set == 1)
		{
			map[i][j].color = set_color_p(map[i][j], map, r_nb);
			j++;
		}
		i++;
	}
}

void	free_tab(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

void	free_map(t_point **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}
