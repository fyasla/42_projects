/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:49:49 by fbougama          #+#    #+#             */
/*   Updated: 2021/09/02 17:37:29 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy_start;
	t_list	*e;

	if (!(*f) || !del || !lst)
		return (NULL);
	cpy_start = ft_lstnew((*f)(lst->content));
	if (!cpy_start)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		e = ft_lstnew((*f)(lst->content));
		if (!e)
			ft_lstclear(&cpy_start, del);
		ft_lstadd_back(&cpy_start, e);
		lst = lst->next;
	}
	return (cpy_start);
}
