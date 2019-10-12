#include <stdlib.h>

void	ft_putnbr_fd(int n, int fd);

int		main(int ac, char **av)
{
	(void)ac;
	ft_putnbr_fd(atoi(av[1]), 1);
	return (0);
}