#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi(const char *str);

int	main(int ac, char **av)
{
	(void)	ac;
	printf("atoi\n%d\n", atoi(av[1]));
	printf("ft_atoi\n%d\n", ft_atoi(av[1]));
	return (0);
}