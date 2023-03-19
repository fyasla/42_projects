/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 00:00:18 by faysal            #+#    #+#             */
/*   Updated: 2021/08/29 01:34:42 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_list2 **bottom)
{
	int		temp;
	t_list2	*top;

	top = ft_lst2top(bottom);
	if (!top)
		return ;
	temp = top->content;
	top->content = (top->prev)->content;
	(top->prev)->content = temp;
}

void	rotate(t_list2 **bottom)
{
	if (*bottom)
		*bottom = (*bottom)->prev;
}

void	reverse_rotate(t_list2 **bottom)
{	
	if (*bottom)
		*bottom = (*bottom)->next;
}

void	push_ab(t_list2 **a_bottom, t_list2 **b_bottom)
{
	t_list2	*a_top;

	a_top = ft_lst2top(a_bottom);
	if (!a_top)
		return ;
	ft_lst2addtop(b_bottom, a_top->content);
	ft_lst2deltop(a_bottom);
}

int	stack_length(t_list2 **bottom)
{
	t_list2	*top;
	t_list2	**e;
	int		length;

	top = ft_lst2top(bottom);
	if (!top)
		return (0);
	e = malloc(sizeof(t_list2 *));
	if (!e)
		return (-1);
	length = 1;
	*e = top;
	*e = (*e)->prev;
	while (*e != top)
	{
		length += 1;
		*e = (*e)->prev;
	}
	free(e);
	return (length);
}
