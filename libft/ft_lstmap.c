/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:11:00 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/15 13:49:36 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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
