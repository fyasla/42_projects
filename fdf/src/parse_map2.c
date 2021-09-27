/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:46:19 by faysal            #+#    #+#             */
/*   Updated: 2021/09/27 02:07:44 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	fill_map(t_point **map, char *filename)
{
	int	i;
	int	j;
	char *line;
	int	fd;
	char	**split;
	//char **split;
	int ret;
	(void)map;

	fd = open(filename, O_RDONLY);
	i = 0;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		j = 0;
		split = ft_split(line, ' ');
		while (split[j] != NULL)
		{	
			printf("%d ", ft_atoi(split[j]));
			map[i][j] = coord(i, j, ft_atoi(split[j]));
			j++;
		}
		printf("\nret: %d||line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd, &line);
		i++;
	}
		j = 0;
		split = ft_split(line, ' ');
		while (split[j] != NULL)
		{	
			printf("%d ", ft_atoi(split[j]));
			map[i][j] = coord(i, j, ft_atoi(split[j]));
			j++;
		}
	//map[i] = NULL;
	printf("ret: %d||line: %s\n", ret, line);
	free(line);
	close(fd);
}

void	free_tab(char **tab)
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