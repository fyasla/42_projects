/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 19:52:02 by faysal            #+#    #+#             */
/*   Updated: 2021/08/29 02:00:23 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_index(t_list2 **bottom, int n)
{
	t_list2	*top;
	t_list2	**e;
	int		index;

	top = ft_lst2top(bottom);
	if (!top)
		return (0);
	e = malloc(sizeof(t_list2));
	if (!e)
		return (-1);
	*e = top;
	index = 1;
	while ((*e)->prev != top && (*e)->content != n)
	{
		index ++;
		*e = (*e)->prev;
	}
	if (index > stack_length(bottom))
	{
		free(e);
		return (0);
	}
	free(e);
	return (index);
}

int	stack_min(t_list2 **bottom)
{
	t_list2	*top;
	t_list2	**e;
	int		min;

	top = ft_lst2top(bottom);
	if (!top)
		return (0);
	e = malloc(sizeof(t_list2));
	if (!e)
		return (-1);
	*e = top;
	min = (*e)->content;
	*e = (*e)->prev;
	while (*e != top)
	{
		if ((*e)->content < min)
			min = (*e)->content;
		*e = (*e)->prev;
	}
	free(e);
	return (min);
}

int	stack_max(t_list2 **bottom)
{
	t_list2	*top;
	t_list2	**e;
	int		max;

	top = ft_lst2top(bottom);
	if (!top)
		return (0);
	e = malloc(sizeof(t_list2));
	if (!e)
		return (-1);
	*e = top;
	max = (*e)->content;
	*e = (*e)->prev;
	while (*e != top)
	{
		if ((*e)->content > max)
			max = (*e)->content;
		*e = (*e)->prev;
	}
	free(e);
	return (max);
}

char	*add_inst(char *inst, char *inst_l)
{
	char	*new_list;

	new_list = malloc((ft_strlen(inst_l) + ft_strlen(inst) + 1) * sizeof(char));
	if (!new_list)
		return (NULL);
	ft_bzero(new_list, ft_strlen(inst_l) + ft_strlen(inst) + 1);
	ft_strlcpy(new_list, inst_l, ft_strlen(inst_l) + 1);
	ft_strlcat(new_list, inst, ft_strlen(new_list) + ft_strlen(inst) + 1);
	free (inst_l);
	return (new_list);
}

void	free_stacks(t_stacks *stacks)
{
	ft_lst2clear(stacks->a);
	ft_lst2clear(stacks->b);
	free(stacks);
}
