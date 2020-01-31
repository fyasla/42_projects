/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:11:38 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/31 16:14:57 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../inc/parsing_test.h"

int		main(int ac, char **av)
{
	(void)ac;
	t_scene	scene;
	t_scene *scene_ptr;
	int		map_fd;
	int		i;

	map_fd = open(av[1], O_RDONLY);
	scene_ptr = map_parse(map_fd);
	scene = *scene_ptr;
	
	close(map_fd);
	// i = 0;
	// ft_printf("\n##############################################################\n\nOBJECTS LIST :\n\n");
	// while (i < MAX_OBJS)
	// {
	// 	display_obj(scene.objects[i]);
	// 	i++;
	// 	ft_printf("\n");
	// }
	// ft_printf("\n##############################################################\n\nCAMERAS LIST :\n\n");
	i = 0;
	while (i < MAX_CAMS)
	{
		display_cam(scene.cameras[i]);
		i++;
		ft_printf("\n");
	}
	ft_printf("################################################################\n\nLIGHTS LIST :\n\n");
	i = 0;
	while (i < MAX_LIGHTS)
	{
		display_light(scene.lights[i]);
		ft_printf("\n");
		i++;
	}
	ft_printf("sizeof t_scene : %d\n", sizeof(t_scene));
	ft_printf("sizeof t_scene* : %d\n", sizeof(t_scene*));
	free(scene_ptr);
	//while(1);
}