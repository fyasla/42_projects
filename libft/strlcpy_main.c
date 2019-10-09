#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int		main(int ac, char **av)
{
	(void)ac;
	char	*s1;
	char	*s2;

	s1 = malloc(100);
	s2 = malloc(100);
	memcpy(s1, av[1], 9);
	memcpy(s2, av[2], 7);
	printf("strlcpy\n%d\n", strlcpy(av[1], av[2], atoi(av[3])));
	printf("%s\n%s\n\n", av[1], av[2]);
	printf("s1\n%s\ns2\n%s\n\n", s1, s2);
	printf("ft_strlcpy\n%d\n", ft_strlcpy(s1, s2, atoi(av[3])));
	printf("%s\n%s\n", s1, s2);
	return (0);
}