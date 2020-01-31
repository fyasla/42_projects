/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:11:38 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/31 14:34:39 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../inc/parsing_test.h"

int		main(int ac, char **av)
{
	(void)ac;
	t_scene	scene;
	int		map_fd;
	int		i;

	map_fd = open(av[1], O_RDONLY);
	scene = *map_parse(map_fd);
	
	close(map_fd);
	// while (i < 100)
	// {
	// 	printf("%f\n", scene->lights[0].pos.x);
	// 	i++;
	// }
	// display_light(scene->lights[0]);
	ft_printf("\n##############################################################\n\nCAMERAS LIST :\n\n");
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
}