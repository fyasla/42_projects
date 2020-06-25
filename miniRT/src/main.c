/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:15:03 by fbougama          #+#    #+#             */
/*   Updated: 2020/06/25 20:06:43 by faysal           ###   ########.fr       */
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

int		check_args(int ac, int map_fd, char **av)
{
	if (ac != 2 && (ac != 3 || ft_strncmp(av[2], "-save", 6) != 0))
		ft_printf("Arguments should be one map (and optionnaly \"-save\")\n");
	if (map_fd == -1)
		ft_printf(ft_strjoin("ERROR while opening ", av[1]));
		ft_printf("\n");
	return (0);
}

int		main(int ac, char **av)
{
	t_win	win;
	t_scene *scene;
	int		map_fd;
	char	*img;

	map_fd = open(av[1], O_RDONLY);
	check_args(ac, map_fd, av);
	scene = map_parse(map_fd);
	close(map_fd);
	win.mlx_p = mlx_init();
	win.win_p = mlx_new_window(win.mlx_p, scene->resx, scene->resy, av[1]);
	win.scene = scene;
	img = create_img(&win, scene);
	if (ac == 3 && ft_strncmp(av[2], "-save", 6) == 0)
		gen(scene);
	mlx_key_hook(win.win_p, deal_key, &win);
	mlx_hook(win.win_p, 17, 131072, exit_prog, &win);
	draw(&win, scene, img);
	mlx_loop(win.mlx_p);
	return (0);
}
