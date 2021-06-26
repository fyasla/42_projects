/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 22:28:22 by faysal            #+#    #+#             */
/*   Updated: 2021/06/26 14:48:34 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_list2 **bottom)
{
	t_list2	*e;

	if (!(e = malloc (sizeof(t_list2))))
		return (0);
	e = (*bottom)->next;
	while (e != *bottom)
	{
		if (e->content < (e->next)->content)
			return (0);
		e = e->next;
	}
	return (1);
}

int is_empty(t_list2 **bottom)
{
	if (*bottom == NULL)
		return(1);
	return (0);
}

int	is_ok(t_stacks *stacks)
{
	if(is_sorted(stacks->a) && is_empty(stacks->b))
		return (1);
	else
		return (0);
}