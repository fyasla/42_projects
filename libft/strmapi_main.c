#include <stdio.h>
#include <string.h>

char				ft_invcasse(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					main(int ac, char **av)
{
	(void)ac;
	printf("fonction : \nft_strmapi\n%s\n", ft_strmapi(av[1], &ft_invcasse));
	return (0);
}