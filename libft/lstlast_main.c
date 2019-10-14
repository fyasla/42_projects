#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);

static void	ft_lstprint(t_list **begin)
{
	t_list	*elem;

	elem = *begin;
	while (elem != NULL)
	{
		printf("%s ", elem->content);
		elem = elem->next;
	}
}

int			main(int ac, char **av)
{
	(void)ac;
	t_list	**begin;
	t_list	*e0;
	t_list	*e1;
	t_list	*e2;
	t_list	*e3;

	e0 = ft_lstnew(av[1]);
	e1 = ft_lstnew(av[2]);
	e2 = ft_lstnew(av[3]);
	e3 = ft_lstnew(av[4]);
	
	e0->next = e1;
	e1->next = e2;
	e2->next = e3;
	if(!(begin = malloc (sizeof(e0))))
		return (1);
	*begin = e0;

	printf("initial list : ");
	ft_lstprint(begin);
	printf("\n");

	printf("last elem : %s\n", ft_lstlast(*begin)->content);
	return (0);
}