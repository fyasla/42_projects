#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c);

int	main(int ac, char **av)
{
	(void)ac;

	printf("address\n%p\n", av[1]);
	printf("strrchr\n%p\n", strrchr(av[1], av[2][0]));
	printf("ft_strrchr\n%p", ft_strrchr(av[1], av[2][0]));
	return (0);
}