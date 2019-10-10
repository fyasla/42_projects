#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);

int		main(int ac, char **av)
{
	printf("s1\n%s\ns2\n%s\nft_strjoin\n%s\n", av[1], av[2], ft_strjoin(av[1], av[2]));
	return (0);
}