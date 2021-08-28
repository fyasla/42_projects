/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:24:16 by faysal            #+#    #+#             */
/*   Updated: 2021/08/29 00:23:26 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_list2 **bottom)
{
	t_list2	**e;

	if (is_empty(bottom))
		return (1);
	e = malloc (sizeof(t_list2 *));
	if (!e)
		return (0);
	*e = (*bottom);
	while ((*e)->next != *bottom)
	{
		if ((*e)->content < ((*e)->next)->content)
		{
			free(e);
			return (0);
		}
		*e = (*e)->next;
	}
	free(e);
	return (1);
}

int	is_empty(t_list2 **bottom)
{
	if (*bottom == NULL)
		return (1);
	return (0);
}

int	is_ok(t_stacks *stacks)
{
	if (is_sorted(stacks->a) && is_empty(stacks->b))
		return (1);
	else
		return (0);
}
