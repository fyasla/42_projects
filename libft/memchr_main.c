#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n);

int	main(int ac, char **av)
{
	(void)ac;

	printf("memchr\n%s\n", memchr(av[1], av[2][0], atoi(av[3])));
	printf("ft_memchr\n%s\n", ft_memchr(av[1], av[2][0], atoi(av[3])));
	return (0);
}