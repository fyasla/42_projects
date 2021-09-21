#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	(void)ac;
	int	ret;
	int fd;
	char *line;

	fd = open(av[1], O_RDONLY);
	ret = get_next_line(fd, &line);
	printf("YESSS\n");

	while (ret > 0)
	{
		printf("%s", line);
		ret = get_next_line(fd, &line);
	}
	return(0);
}
