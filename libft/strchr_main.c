#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c);

int	main(int ac, char **av)
{
	(void)ac;

	printf("address\n%p\n", av[1]);
	printf("strchr\n%p\n", strchr(av[1], av[2][1])));
	printf("ft_strchr\n%p", ft_strchr(av[1], av[2][1])));
	return (0);
}