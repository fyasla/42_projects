#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set);

int		main(int ac, char **av)
{
	printf("s\n%s\nft_strtrim\n%s\n", av[1], ft_strtrim(av[1], av[2]));
	return (0);
}