/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 19:52:02 by faysal            #+#    #+#             */
/*   Updated: 2021/08/28 19:53:19 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
