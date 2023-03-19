/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:50:21 by faysal            #+#    #+#             */
/*   Updated: 2021/08/28 22:21:03 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*sort(t_stacks *stacks, char *inst_list)
{
	int		stack_l;

	stack_l = stack_length(stacks ->a);
	if (stack_l == 0 || stack_l == 1 || is_ok(stacks))
		return (inst_list);
	else if (stack_l == 2)
		return (sort_2(stacks->a, inst_list));
	else if (stack_l == 3)
		return (sort_3(stacks->a, inst_list));
	else if (stack_l > 3 && stack_l <= 10)
		return (sort_10(stacks, inst_list));
	else
		return (sort_plus(stacks, inst_list));
	return (inst_list);
}

char	*sort_2(t_list2 **bottom, char *inst_list)
{
	if (!is_sorted(bottom))
		inst_list = add_inst("sa\n", inst_list);
	return (inst_list);
}

char	*sort_3(t_list2 **a_bottom, char *inst_list)
{
	int	bottom;
	int	middle;

	bottom = (*a_bottom)->content;
	middle = (*a_bottom)->next->content;
	if (bottom == stack_max(a_bottom) && middle == stack_min(a_bottom))
		inst_list = add_inst("sa\n", inst_list);
	else if (bottom != stack_min(a_bottom)
		&& bottom != stack_max(a_bottom) && middle == stack_max(a_bottom))
	{
		inst_list = add_inst("rra\n", inst_list);
		inst_list = add_inst("sa\n", inst_list);
	}
	else if (bottom == stack_min(a_bottom) && middle != stack_min(a_bottom)
		&& middle != stack_max(a_bottom))
	{
		inst_list = add_inst("ra\n", inst_list);
		inst_list = add_inst("sa\n", inst_list);
	}
	else if (bottom == stack_min(a_bottom) && middle == stack_max(a_bottom))
		inst_list = add_inst("rra\n", inst_list);
	else if (bottom != stack_min(a_bottom)
		&& bottom != stack_max(a_bottom) && middle == stack_min(a_bottom))
		inst_list = add_inst("ra\n", inst_list);
	return (inst_list);
}

char	*sort_10(t_stacks *stacks, char *inst_list)
{
	while (stack_length(stacks->a) > 3)
		inst_list = push_min_ab(stacks->a, stacks->b, inst_list);
	inst_list = sort_3(stacks->a, inst_list);
	while (stack_length(stacks->b) > 0)
	{
		inst_list = add_inst("pa\n", inst_list);
		push_ab(stacks->b, stacks->a);
	}
	return (inst_list);
}

char	*sort_plus(t_stacks *stacks, char *inst_list)
{
	inst_list = divide(stacks, nb_of_sets(stack_length(stacks->a)), inst_list);
	while (stack_length(stacks->a) > 3)
		inst_list = push_min_ab(stacks->a, stacks->b, inst_list);
	if (stack_length(stacks->a) == 3)
		inst_list = sort_3(stacks->a, inst_list);
	else if (stack_length(stacks->a) == 2)
		inst_list = sort_2(stacks->a, inst_list);
	while (stack_length(stacks->b) > 0)
		inst_list = push_max_ab(stacks->b, stacks->a, inst_list);
	return (inst_list);
}
