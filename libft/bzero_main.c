#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_bzero(void *s, size_t n);

int	main(int ac, char **av)
{
	(void)	ac;
	void	*ptr1;
	void	*ptr2;

	ptr1 = malloc(100);
	ptr2 = malloc(100);
	printf("ft_bzero\n%s\n", ft_bzero(ptr1, atoi(av[1])));
	printf("bzero\n%s\n", bzero(ptr2, atoi(av[1])));
	return (0);
}