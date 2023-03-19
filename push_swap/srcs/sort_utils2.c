/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 19:52:15 by faysal            #+#    #+#             */
/*   Updated: 2021/08/29 01:00:56 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*push_min_ab(t_list2 **a_btm, t_list2 **b_btm, char *inst_list)
{
	if (get_index(a_btm, stack_min(a_btm)) <= stack_length(a_btm) / 2)
	{
		while (get_index(a_btm, stack_min(a_btm)) != 1)
		{	
			inst_list = add_inst("ra\n", inst_list);
			rotate(a_btm);
			if (get_index(a_btm, stack_min(a_btm)) == 0)
				return (NULL);
		}
	}
	else
	{
		while (get_index(a_btm, stack_min(a_btm)) != 1)
		{	
			inst_list = add_inst("rra\n", inst_list);
			reverse_rotate(a_btm);
			if (get_index(a_btm, stack_min(a_btm)) == 0)
				return (NULL);
		}
	}
	inst_list = add_inst("pb\n", inst_list);
	push_ab(a_btm, b_btm);
	return (inst_list);
}

char	*push_max_ab(t_list2 **a_btm, t_list2 **b_btm, char *inst_list)
{
	if (get_index(a_btm, stack_max(a_btm)) <= stack_length(a_btm) / 2)
	{
		while (get_index(a_btm, stack_max(a_btm)) != 1)
		{	
			inst_list = add_inst("rb\n", inst_list);
			rotate(a_btm);
			if (get_index(a_btm, stack_max(a_btm)) == 0)
				return (NULL);
		}
	}
	else
	{
		while (get_index(a_btm, stack_max(a_btm)) != 1)
		{	
			inst_list = add_inst("rrb\n", inst_list);
			reverse_rotate(a_btm);
			if (get_index(a_btm, stack_max(a_btm)) == 0)
				return (NULL);
		}
	}
	inst_list = add_inst("pa\n", inst_list);
	push_ab(a_btm, b_btm);
	return (inst_list);
}

char	*divide(t_stacks *stacks, int n, char *inst_list)
{
	int	c;
	int	lim;

	c = 1;
	while (c < n)
	{
		lim = (int)((stack_length(stacks->a) + stack_length(stacks->b)) / n);
		lim = c * lim;
		while (stack_length(stacks->b) < lim)
		{
			if (ft_lst2top(stacks->a)->content <= lim)
			{
				push_ab(stacks->a, stacks->b);
				inst_list = add_inst("pb\n", inst_list);
			}
			else
			{
				rotate(stacks->a);
				inst_list = add_inst("ra\n", inst_list);
			}
		}
		c++;
	}
	return (inst_list);
}

int	nb_of_sets(int size)
{
	return ((int)(0.015 * size + 3.5));
}

void	ft_lst2clear(t_list2 **bottom)
{
	while (stack_length(bottom) > 0)
	{
		ft_lst2deltop(bottom);
	}
	free(bottom);
}
