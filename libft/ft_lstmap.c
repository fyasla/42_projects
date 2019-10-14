/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:11:00 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/14 16:37:34 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list*))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

static t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static void		ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*penult;

	penult = ft_lstlast(*alst);
	penult->next = new;
	new->next = NULL;
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	**cpy_start;
	t_list	*e;
	void	*content;

	if (!(cpy_start = (t_list**)malloc(sizeof(cpy_start))))
		return (NULL);
	while (lst != NULL)
	{
		content = lst->content;
		e = ft_lstnew((*f)(content));
		ft_lstadd_back(cpy_start, e);
		lst = lst->next;
	}
	return (*cpy_start);
}
