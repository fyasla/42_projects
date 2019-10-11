#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);

int		main(int ac, char **av)
{
	(void)	ac;
	char	**tab;
	tab = ft_split(av[1], av[2][0]);
	while (*tab)
		printf("%s\n", *tab++);
	printf("%p\n", *tab);
	return (0);
}