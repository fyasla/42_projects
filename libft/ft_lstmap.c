/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:49:49 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/22 17:51:12 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**cpy_start;
	t_list	*e;
	void	*content;

	if (!(*f) || !del || !lst)
		return (NULL);
	if (!(cpy_start = (t_list**)malloc(sizeof(cpy_start))))
		return (NULL);
	*cpy_start = ft_lstnew((*f)(lst->content));
	lst = lst->next;
	while (lst != NULL)
	{
		content = lst->content;
		if (!(e = ft_lstnew((*f)(content))))
			ft_lstclear(cpy_start, del);
		ft_lstadd_back(cpy_start, e);
		lst = lst->next;
	}
	return (*cpy_start);
}

