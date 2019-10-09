#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	main(int ac, char **av)
{
	(void)ac;
	printf("memcmp\n%d\n", memcmp(av[1], av[2], atoi(av[3])));
	printf("ft_memcmp\n%d\n", ft_memcmp(av[1], av[2], atoi(av[3])));
	return (0);
}