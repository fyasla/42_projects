#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int n);

int		main(int ac, char **av)
{
	(void)ac;
	printf("ft_atoi\n%s\n", ft_itoa(atoi(av[1])));
	return (0);
}