/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:49:13 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/22 17:41:10 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*e;

	if (!lst || !del)
		return ;
	e = *lst;
	while (e != NULL)
	{
		ft_lstdelone(e, del);
		e = e->next;
	}
	*lst = NULL;
}
