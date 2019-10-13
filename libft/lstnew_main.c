#include <stdio.h>
#include "libft.h"

t_list	*ft_lstnew(void *content);
char	*ft_strdup(const char *s1);

int		main(int ac, char **av)
{
	(void)ac;
	t_list	*new;

	new = ft_lstnew(av[1]);
	printf("content :\n%s\nnext :\n%p\n", new->content, new->next);
	return (0);
}