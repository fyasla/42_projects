/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:04:17 by faysal            #+#    #+#             */
/*   Updated: 2021/06/24 00:29:08 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list2	*ft_lst2new(int content)
{
	t_list2	*new;

	if (!(new = (t_list2*)malloc(sizeof(t_list2))))
		return (NULL);
	new->prev = NULL;
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lst2addtop(t_list2 **bottom, t_list2 *new)
{
	if (!(*bottom))
		*bottom = new;
	else
	{
		if (!ft_lst2top(bottom))
			return ;
		(ft_lst2top(bottom))->next = new;
		new->prev = ft_lst2top(bottom);
	}
	new->next = *bottom;
	(*bottom)->prev = new;
}

void	ft_lst2deltop(t_list2 **bottom)
{
	t_list2	*top;

	if(!(top = malloc(sizeof(t_list2))))
		return ;
	if (!(*bottom))
		return ;
	if (!(top = ft_lst2top(bottom)))
		return ;
	if (*bottom == top)
		*bottom = NULL;
	(top->prev)->next = top->next;
	(top->next)->prev = top->prev;
	free(top);
}

t_list2	*ft_lst2top(t_list2 **bottom)
{
	if (!(*bottom))
		return (NULL);
	return ((*bottom)->prev);
}
