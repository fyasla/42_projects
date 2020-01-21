/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:47:53 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/21 15:08:50 by fbougama         ###   ########.fr       */
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

void	map_parse(int map_fd)
{
	char	*line;
	int		cpt[3];
	t_scene	scene;

	cpt[0] = 0;
	cpt[1] = 0;
	cpt[2] = 0;
	while (get_next_line(map_fd, &line) > 0)
	{
		// printf("%d:%d %s\n", retour, i, line);
		//if (line_parse(line, &cpt, &scene) == -1)
		//	return (NULL);
		free(line);
	}
	//line_parse(line, &cpt);
	free(line);
}

/*int			line_parse(char *line)
{
	if (line[0] == 'R')
		parse_R(line);
	else if (line[0] == 'A')
		parse_A(line);
	else if (line[0] == 'c' && line[1] != 'y')
		parse_c(line);
	else if (line[0] == 'l')
		parse_l(line);
	else if (line[0] == 'l')
		parse_l(line);
	
}
*/
