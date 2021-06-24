/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 00:00:18 by faysal            #+#    #+#             */
/*   Updated: 2021/06/24 00:30:44 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_list2 **bottom)
{
	int		temp;
	t_list2	*top;

	top = malloc(sizeof(t_list2));
	top = ft_lst2top(bottom);
	temp = top->content;
	top->content = (top->prev)->content;
	(top->prev)->content = temp;
	free(top);
}

void	rotate(t_list2 **bottom)
{
	*bottom = (*bottom)->prev;
}

void	reverse_rotate(t_list2 **bottom)
{
	*bottom = (*bottom)->next;
}

void	push_ab(t_list2 **a_bottom, t_list2 **b_bottom)
{
	t_list2	*a_top;

	if (!(a_top = ft_lst2top(a_bottom)))
		return ;
	ft_lst2addtop(b_bottom, a_top);
	ft_lst2deltop(a_bottom);
}

void	print_stack(t_list2 **bottom)
{
	t_list2	*top;
	t_list2 *e;

	if (!(top = ft_lst2top(bottom)))
		return ;
	if (!(e = malloc(sizeof(t_list2))))
		return ;
	e = top;
	printf("%d\n", e->content);
	e = e->prev;
	while (e != top)
	{
		printf("%d\n", e->content);
		e = e->prev;	
	}
}