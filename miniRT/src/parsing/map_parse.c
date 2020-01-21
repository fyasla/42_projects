/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:47:53 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/21 17:55:16 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		retour;
	int		i;

	i = 1;
	(void)argc;
	fd = open(argv[1], O_RDONLY);
	while ((retour = get_next_line(fd, &line)) > 0)
	{
		printf("%d:%d %s\n", retour, i, line);
		i++;
		free(line);
	}
	printf("%d:%d %s\n", retour, i, line);
	free(line);
	close(fd);
	//while(1);
}

void	scene_initiate(t_scene *scene_ptr)
{
	scene_ptr->resX = -1;
	scene_ptr->resY = -1;
}

void	map_parse(int map_fd)
{
	char	*line;
	int		cpt[3];
	t_scene	scene;

	cpt[0] = 0;
	cpt[1] = 0;
	cpt[2] = 0;
	scene_initiate(&scene);
	while (get_next_line(map_fd, &line) > 0)
	{
		// printf("%d:%d %s\n", retour, i, line);
		if (line_parse(line, &cpt, &scene) == -1)
			return ;
		free(line);
	}
	//line_parse(line, &cpt);
	free(line);
}

int		line_parse(char *line, int **cpt_ptr, t_scene *scene_ptr)
{
	if (line[0] == 'R')
		parse_R(line, cpt_ptr, scene_ptr);
	else if (line[0] == 'A')
		parse_A(line, cpt_ptr, scene_ptr);
	else if (line[0] == 'c' && line[1] != 'y')
		parse_c(line, cpt_ptr, scene_ptr);
	else if (line[0] == 'l')
		parse_l(line, cpt_ptr, scene_ptr);
	else if (line[0] == 's' && line[1] == 'p')
		parse_sp(line, cpt_ptr, scene_ptr);
	else if (line[0] == 's' && line[1] == 'q')
		parse_sq(line, cpt_ptr, scene_ptr);
	else if (line[0] == 'c' && line[1] == 'y')
		parse_cy(line, cpt_ptr, scene_ptr);
	else if (line[0] == 't' && line[1] == 'r')
		parse_tr(line, cpt_ptr, scene_ptr);
	else
	{
		write(1, "ERROR\nA line must be empty or start with a valid identifier", 50);
		return (-1);
	}
	return (0);
}

