/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:47:53 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/31 16:35:15 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/*
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
}*/

void	display_cam(t_cam camera);
void	display_light(t_light light);

t_scene	*map_parse(int map_fd)
{
	char	*line;
	int		*cpt;
	t_scene	*scene_ptr;

	// scene.lights[0].lum_rat = 0.0;
	// scene.lights[0].color.r = 0;
	// scene.lights[0].color.g = 0;
	// scene.lights[0].color.b = 0;
	// scene.lights[0].pos.x = 0.0;
	// scene.lights[0].pos.y = 0.0;
	// scene.lights[0].pos.z = 0.0;

	if(!(cpt = malloc(3 * sizeof(int))))
		return (NULL);
	if(!(scene_ptr = malloc(sizeof(t_scene))))
		return (NULL);
	cpt[0] = 0;
	cpt[1] = 0;
	cpt[2] = 0;
	scene_initiate(scene_ptr);
	while (get_next_line(map_fd, &line) > 0)
	{
		ft_printf("new linee \n\n");
		if (line_parse(line, cpt, scene_ptr) == -1)
		{
			free(line);
			free(cpt);
			ft_printf("\n\n\n\n\n\nERROR\n\n\n\n\n\n\n\n\n\n\n");
			return (scene_ptr);
		}
		free(line);
	}
	//line_parse(line, &cpt);
	free(cpt);
	free(line);
	return(scene_ptr);
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
	// else if (line[0] == 's' && line[1] == 'q')
	// 	ret = parse_sq(line, cpt_ptr, scene_ptr);
	// else if (line[0] == 'c' && line[1] == 'y')
	// 	ret = parse_cy(line, cpt_ptr, scene_ptr);
	// else if (line[0] == 't' && line[1] == 'r')
	// 	ret = parse_tr(line, cpt_ptr, scene_ptr);
	else
	{
		//write(1, "ERROR\nA line must be empty or s 
		//tart with a valid identifier", 50);
		return (-1);
	}
	return (ret);
}
