/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:50:21 by faysal            #+#    #+#             */
/*   Updated: 2021/08/28 18:18:09 by faysal           ###   ########.fr       */
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
		return (sort_2(stacks, inst_list));
	else if (stack_l == 3)
		return (sort_3_asc(stacks->a, inst_list));
	else if (stack_l > 3 && stack_l <= 10)
		return (sort_10(stacks, inst_list));
	else
		return (sort_100(stacks, inst_list));
	inst_list = refactor(inst_list);
	return (inst_list);
}

char	*refactor(char *inst_list)
{
	return (inst_list);
}

char	*add_inst(char *inst, char *inst_list)
{
	char	*new_list;

	if (!(new_list = malloc((ft_strlen(inst_list) + ft_strlen(inst) + 1) * sizeof(char))))
		return (NULL);
	ft_bzero(new_list, ft_strlen(inst_list) + ft_strlen(inst) + 1);
	ft_strlcpy(new_list, inst_list, ft_strlen(inst_list) + 1);
	ft_strlcat(new_list, inst, ft_strlen(new_list) + ft_strlen(inst) + 1);
	free (inst_list);
	return (new_list);
}

char	*sort_2(t_stacks *stacks, char *inst_list)
{
	if (!is_sorted(stacks->a))
		inst_list = add_inst("sa\n", inst_list);
	return (inst_list);
}

char	*sort_3_asc(t_list2 **a_bottom, char *inst_list)
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

char	*divide(t_stacks *stacks, int n, char *inst_list)
{
	int	c;
	int	lim;

	c = 1;
	while (c < n)
	{
		lim = (stack_length(stacks->a) + stack_length(stacks->b)) / n;
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
