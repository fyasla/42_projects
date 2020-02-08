/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:47:53 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/07 16:27:30 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_scene	*map_parse(int map_fd)
{
	char	*line;
	int		cpt[3];
	t_scene	*scene_ptr;

	if (!(scene_ptr = malloc(sizeof(t_scene))))
		return (NULL);
	cpt[0] = 0;
	cpt[1] = 0;
	cpt[2] = 0;
	scene_initiate(scene_ptr);
	while (get_next_line(map_fd, &line) > 0)
	{
		if (line_parse(line, cpt, scene_ptr) == -1)
		{
			free(line);
			ft_printf("\n\n\n\n\n\nERROR\n\n\n\n\n\n\n\n\n\n\n");
			return (scene_ptr);
		}
		free(line);
	}
	if (line_parse(line, cpt, scene_ptr) == -1)
	{
		free(line);
		ft_printf("\n\n\n\n\n\nERROR\n\n\n\n\n\n\n\n\n\n\n");
		return (scene_ptr);
	}
	free(line);
	return (scene_ptr);
}

int		line_parse(char *line, int *cpt, t_scene *scene_ptr)
{
	int ret;

	ret = 0;
	if (line[0] == '\0')
		return (0);
	else if (line[0] == 'R')
		ret = parse_r(line, scene_ptr);
	else if (line[0] == 'A')
		ret = parse_a(line, scene_ptr);
	else if (line[0] == 'c' && line[1] != 'y')
		ret = parse_c(line, cpt, scene_ptr);
	else if (line[0] == 'l')
		ret = parse_l(line, cpt, scene_ptr);
	else if (line[0] == 'p' && line[1] == 'l')
		ret = parse_pl(line, cpt, scene_ptr);
	else if (line[0] == 's' && line[1] == 'p')
		ret = parse_sp(line, cpt, scene_ptr);
	else if (line[0] == 's' && line[1] == 'q')
		ret = parse_sq(line, cpt, scene_ptr);
	else if (line[0] == 'c' && line[1] == 'y')
		ret = parse_cy(line, cpt, scene_ptr);
	else if (line[0] == 't' && line[1] == 'r')
		ret = parse_tr(line, cpt, scene_ptr);
	else if (line[0] == '#')
		return (0);
	else
	{
		//write(1, "ERROR\nA line must be empty or s 
		//tart with a valid identifier", 50);
		return (-1);
	}
	return (ret);
}
