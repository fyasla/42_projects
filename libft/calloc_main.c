#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size);

int	main(int ac, char **av)
{
	(void)	ac;
	printf("calloc\n%p\n", calloc(atoi(av[1]), atoi(av[2])));
	printf("ft_calloc\n%p\n", ft_calloc(atoi(av[1]), atoi(av[2])));
	return (0);
}