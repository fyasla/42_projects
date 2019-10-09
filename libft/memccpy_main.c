#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

int	main(int ac, char **av)
{
	(void)ac;
	printf("ft_memccpy\n%s\n", ft_memccpy(av[1],av[2],av[3][0], atoi(av[4])));
	printf("memccpy\n%s\n", memccpy(av[1],av[2],av[3][0], atoi(av[4])));
	return (0);
}