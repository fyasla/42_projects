/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:42:29 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/16 12:42:34 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

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
