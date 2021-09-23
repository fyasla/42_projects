/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:08:39 by faysal            #+#    #+#             */
/*   Updated: 2021/09/23 14:30:33 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	row_nb(char *filename)
{
	int		fd;
	int		ret;
	char	*line;
	int		n;

	fd = open(filename, O_RDONLY);
	n = 0;
	ret = get_next_line(fd, &line);
	while (ret > 0 && ft_strlen(line) > 0)
	{
		n++;
		free(line);
		ret = get_next_line(fd, &line);
	}
	if (ft_strlen(line) > 0)
		n++;
	free(line);
	close(fd);
	return (n);
}
