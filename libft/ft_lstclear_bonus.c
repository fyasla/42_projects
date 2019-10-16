/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:41:36 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/16 18:02:55 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

static void	ft_delone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*e;

	e = *lst;
	while (e != NULL)
	{
		ft_delone(e, del);
		e = e->next;
	}
	*lst = NULL;
}
