/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:04:17 by faysal            #+#    #+#             */
/*   Updated: 2021/08/29 00:50:03 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list2	*ft_lst2new(int content)
{
	t_list2	*new;

	new = (t_list2 *)malloc(sizeof(t_list2));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lst2addtop(t_list2 **bottom, int content)
{
	t_list2	*top;
	t_list2	*new;

	new = ft_lst2new(content);
	if (!new)
		return ;
	if (!(*bottom))
		*bottom = new;
	else
	{
		top = ft_lst2top(bottom);
		if (!top)
			return ;
		top->next = new;
		new->prev = top;
	}
	new->next = *bottom;
	(*bottom)->prev = new;
}

void	ft_lst2deltop(t_list2 **bottom)
{
	t_list2	*top;

	if (!(*bottom))
		return ;
	top = ft_lst2top(bottom);
	if (!top)
		return ;
	(top->prev)->next = top->next;
	(top->next)->prev = top->prev;
	free(top);
	if (*bottom == top)
		*bottom = NULL;
}

t_list2	*ft_lst2top(t_list2 **bottom)
{
	if (!(*bottom))
		return (NULL);
	return ((*bottom)->prev);
}

int	is_integer(char *str)
{
	unsigned int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != 0 && ft_isdigit(str[i]))
		i++;
	if (i < ft_strlen(str))
		return (0);
	else
		return (check_int_range(str));
}
