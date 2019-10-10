#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n);

int		main(int ac, char **av)
{
	(void)ac;

	printf("address\n%p\n\nstrnstr\n%p\n", av[1],strnstr(av[1], av[2], atoi(av[3])));
	printf("ft_strnstr\n%p\n", ft_strnstr(av[1], av[2], atoi(av[3])));
	return (0);
}