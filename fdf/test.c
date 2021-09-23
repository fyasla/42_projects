#include <stdio.h>
#include "inc/fdf.h"


int	row_number(char *filename)
{
	int fd;
	int	ret;
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
	if(ft_strlen(line) > 0)
		n++;
	free(line);
	close(fd);
	return (n);
}

int	main(int ac, char **av)
{	
	int	fd;
	int	ret;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		return (1);
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		printf("ret: %d||line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd, &line);
	}
	printf("ret: %d||line: %s\n", ret, line);
	free(line);
	close(fd);
	printf("\nThere are %d lines\n", row_number(av[1]));
	return (0);
}
