/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:49:13 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/22 19:40:11 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*e;
	t_list	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	e = *lst;
	while (e)
	{
		tmp = e;
		e = e->next;
		ft_lstdelone(tmp, del);
	}
	*lst = NULL;
}
