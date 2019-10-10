#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

int		main(int ac, char **av)
{
	printf("s\n%s\nft_substr\n%s\n", av[1], ft_substr(av[1], atoi(av[2]), atoi(av[3])));
	return (0);
}