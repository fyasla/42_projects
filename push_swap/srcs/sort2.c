/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:48:49 by faysal            #+#    #+#             */
/*   Updated: 2021/08/28 15:33:09 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*sort_10(t_stacks *stacks, char *inst_list)
{
	while (stack_length(stacks->a) > 3)
		inst_list = push_min_ab(stacks->a, stacks->b, inst_list);
	inst_list = sort_3_asc(stacks->a, inst_list);
	while (stack_length(stacks->b) > 0)
	{
		inst_list = add_inst("pa\n", inst_list);
		push_ab(stacks->b, stacks->a);
	}
	return (inst_list);
}

char	*push_min_ab(t_list2 **a_bottom, t_list2 **b_bottom, char *inst_list)
{
	int	index_min;

	index_min = get_index(a_bottom, stack_min(a_bottom));
	if (index_min <= stack_length(a_bottom) / 2)
	{
		while (index_min != 1)
		{	
			inst_list = add_inst("ra\n", inst_list);
			rotate(a_bottom);
			index_min = get_index(a_bottom, stack_min(a_bottom));
			if (index_min == 0)
				return (NULL);
		}
		inst_list = add_inst("pb\n", inst_list);
		push_ab(a_bottom, b_bottom);
	}
	else
	{
		while (index_min != 1)
		{	
			inst_list = add_inst("rra\n", inst_list);
			reverse_rotate(a_bottom);
			index_min = get_index(a_bottom, stack_min(a_bottom));
			if (index_min == 0)
				return (NULL);
		}
		inst_list = add_inst("pb\n", inst_list);
		push_ab(a_bottom, b_bottom);
	}
	return (inst_list);
}

int	stack_min(t_list2 **bottom)
{
	t_list2	*top;
	t_list2	*e;
	int		min;

	top = ft_lst2top(bottom);
	if (!top)
		return (0);
	if (!(e = malloc(sizeof(t_list2))))
		return (-1);
	e = top;
	min = e->content;
	e = e->prev;
	while (e != top)
	{
		if (e->content < min)
			min = e->content;
		e = e->prev;
	}
	return (min);
}

int	get_index(t_list2 **bottom, int n)
{
	t_list2	*top;
	t_list2	*e;
	int		index;

	top = ft_lst2top(bottom);
	if (!top)
		return (0);
	if (!(e = malloc(sizeof(t_list2))))
		return (-1);
	e = top;
	index = 1;
	while (e->prev != top && e->content != n)
	{
		index ++;
		e = e->prev;
	}
	if (index > stack_length(bottom))
		return (0);
	return (index);
}

int	stack_max(t_list2 **bottom)
{
	t_list2	*top;
	t_list2	*e;
	int		max;

	top = ft_lst2top(bottom);
	if (!top)
		return (0);
	if (!(e = malloc(sizeof(t_list2))))
		return (-1);
	e = top;
	max = e->content;
	e = e->prev;
	while (e != top)
	{
		if (e->content > max)
			max = e->content;
		e = e->prev;
	}
	return (max);
}
