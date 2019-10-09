#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);

int	main(int ac, char **av)
{
	(void)	ac;
	void	*ptr1;
	void	*ptr2;

	ptr1 = malloc(1000);
	ptr2 = malloc(1000);
	printf("ft_memcpy\n%s\n", ft_memcpy(ptr1, av[1], atoi(av[2])));
	printf("memcpy\n%s\n", memcpy(ptr2, av[1], atoi(av[2])));
	return (0);
}