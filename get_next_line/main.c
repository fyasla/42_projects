/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:51:15 by fbougama          #+#    #+#             */
/*   Updated: 2019/11/26 10:51:55 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
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
}