#include <stdio.h>
#include <string.h>

char	*ft_strdup(const char *s1);

int		main(int ac, char **av)
{
	(void) ac;
	printf("strdup\n%s\n", strdup(av[1]));
	printf("ft_strdup\n%s\n", ft_strdup(av[1]));
	return (0);
}