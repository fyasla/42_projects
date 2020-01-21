/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:11:38 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/21 19:20:53 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		main(int ac, char **av)
{
	t_scene	scene;

	(void)ac;
	map_fd = open(argv[1], O_RDONLY);
	scene = map_parse(map_fd);
	close(fd);
}