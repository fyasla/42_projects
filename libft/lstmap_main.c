#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list		*ft_lstnew(void *content);
t_list 		*ft_lstmap(t_list *lst, void *(*f)(void *));

static void	ft_f(void* ptr)
{
	char	*str;

	str = (char*)ptr;
	while (*str)
		*str++ = '5';
}

static void	ft_lstprint(t_list **begin)
{
	t_list	*elem;

	elem = *begin;
	while (elem != NULL)
	{
		printf("%s ", elem->content);
		elem = elem->next;
	}
	printf("\n");
}

int			main(int ac, char **av)
{
	(void)ac;
	t_list	**begin;
	t_list	*new_begin;
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
		return (-1);
	*begin = e0;

	printf("initial list : ");
	ft_lstprint(begin);

	new_begin = ft_lstmap(*begin, ft_f);

	printf("initial list after lstmap : ");
	ft_lstprint(begin);

	printf("new list after lstmap : ");
	ft_lstprint(&new_begin);
	return (0);
}