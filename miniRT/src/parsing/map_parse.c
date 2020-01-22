/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:47:53 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/22 13:46:37 by fbougama         ###   ########.fr       */
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

t_scene	*map_parse(int map_fd)
{
	char	*line;
	int		cpt[3];
	t_scene	scene;
	t_scene	*scene_ptr;

	scene_ptr = &scene;
	cpt[0] = 0;
	cpt[1] = 0;
	cpt[2] = 0;
	scene_initiate(scene_ptr);
	while (get_next_line(map_fd, &line) > 0)
	{
		if (line_parse(line, cpt, scene_ptr) == -1)
			return (NULL);
		free(line);
	}
	//line_parse(line, &cpt);
	free(line);
	return(scene_ptr);
}

int		line_parse(char *line, int *cpt, t_scene *scene_ptr)
{
	int ret;

	(void)cpt;

	if (line[0] == 'R')
		ret = parse_r(line, scene_ptr);
	else if (line[0] == 'A')
		ret = parse_a(line, scene_ptr);
	else if (line[0] == 'c' && line[1] != 'y')
		ret = parse_c(line, cpt, scene_ptr);
	// else if (line[0] == 'l')
	// 	ret = parse_l(line, cpt_ptr, scene_ptr);
	// else if (line[0] == 's' && line[1] == 'p')
	// 	ret = parse_sp(line, cpt_ptr, scene_ptr);
	// else if (line[0] == 's' && line[1] == 'q')
	// 	ret = parse_sq(line, cpt_ptr, scene_ptr);
	// else if (line[0] == 'c' && line[1] == 'y')
	// 	ret = parse_cy(line, cpt_ptr, scene_ptr);
	// else if (line[0] == 't' && line[1] == 'r')
	// 	ret = parse_tr(line, cpt_ptr, scene_ptr);
	else
	{
		write(1, "ERROR\nA line must be empty or s \
		tart with a valid identifier", 50);
		return (-1);
	}
	return (ret);
}
