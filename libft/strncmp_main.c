#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strncmp(const void *s1, const void *s2, size_t n);

int	main(int ac, char **av)
{
	(void)ac;
	printf("strncmp\n%d\n", strncmp(av[1], av[2], atoi(av[3])));
	printf("ft_strncmp\n%d\n", ft_strncmp(av[1], av[2], atoi(av[3])));
	return (0);
}