/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:30:24 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/14 11:54:01 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_delone(t_list *lst, void (*del)(void*))
{
	del(lst);
	free(lst);
}

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*e;

	e = *lst;
	while (*e)
	{
		ft_delone(e, del);
		e = e->next;
	}
	*lst = NULL;
}
