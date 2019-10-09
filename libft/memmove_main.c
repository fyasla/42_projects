#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len);

int	main(int ac, char **av)
{
	(void)ac;

	// !!! test lines 1 by 1 
	printf("memmove\n%s\n", memmove(av[1],av[1] + atoi(av[2]), atoi(av[3])));
	printf("ft_memmove\n%s\n", ft_memmove(av[1],av[1] + atoi(av[2]), atoi(av[3])));
	return (0);
}