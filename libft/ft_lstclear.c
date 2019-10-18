/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:49:13 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/18 19:12:04 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list *lst, void (*del)(void*))
{
	(*del)(lst->content);
	free(lst);
}

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*e;

	e = *lst;
	while (e != NULL)
	{
		ft_lstdelone(e, del);
		e = e->next;
	}
	*lst = NULL;
}
