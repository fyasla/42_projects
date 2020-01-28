/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:11:38 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/28 15:21:29 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../inc/parsing_test.h"

int		main(int ac, char **av)
{
	(void)ac;
	t_scene	*scene;
	int		map_fd;
	int		i;

	i = 0;
	map_fd = open(av[1], O_RDONLY);
	scene = map_parse(map_fd);
	ft_printf("OBJECTS LIST :\n\n");
	// while (scene->objects[i].type)
	// 	display_obj(scene->objects[i++]);
	ft_printf("CAMERAS LIST :\n\n");
	i = 0;
	while (i < MAX_CAMS)
		display_cam(scene->cameras[i++]);
	close(map_fd);
}