/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:15:03 by fbougama          #+#    #+#             */
/*   Updated: 2020/03/12 17:34:04 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		main(int ac, char **av)
{
	t_win	win;
	t_scene *scene;
	int		map_fd;
	char	*img;

	if (ac != 2 && (ac != 3 || ft_strncmp(av[2], "-save", 6) != 0))
	{
		ft_printf("Arguments should be one map (and optionnaly \"-save\")\n");
		return (0);
	}
	map_fd = open(av[1], O_RDONLY);
	scene = map_parse(map_fd);
	close(map_fd);
	win.mlx_p = mlx_init();
	win.win_p = mlx_new_window(win.mlx_p, scene->resx, scene->resy, av[1]);
	win.scene = scene;
	img = create_img(&win, scene);
	draw(&win, scene, img);
	mlx_hook(win.win_p, 1, 1L << 8, &exit_prog, &win);
	mlx_key_hook(win.win_p, &deal_key, &win);
	mlx_loop(win.mlx_p);
	return (0);
}
