/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_transfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:44:35 by faysal            #+#    #+#             */
/*   Updated: 2021/08/28 19:23:47 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*cpy_stack_to_tab(t_list2 **bottom)
{
	int		size;
	int		*tab;
	int		i;
	t_list2	*e;

	size = stack_length(bottom);
	i = size - 1;
	tab = malloc(sizeof(int) * size);
	e = malloc(sizeof(t_list2));
	if (!e)
		return (NULL);
	if (!tab)
		return (NULL);
	e = *bottom;
	while (i >= 0)
	{
		tab[i] = e->content;
		e = e->next;
		i--;
	}
	return (tab);
}

int	*bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j + 1] < tab[j])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	get_index_tab(int n, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size && n != tab [i])
		i++;
	if (i == size)
		return (-1);
	return (i);
}

void	tab_to_stack(t_list2 **bottom, int *tab, int size)
{
	t_list2	*top;
	t_list2	*e;

	if (!(top = ft_lst2top(bottom)))
		return ;
	if (!(e = malloc(sizeof(t_list2))))
		return ;
	e = top;
	e->content = get_index_tab(e->content, tab, size) + 1;
	e = e->prev;
	while (e != top)
	{
		e->content = get_index_tab(e->content, tab, size) + 1;
		e = e->prev;
	}
}

void	stack_transfo(t_list2 **bottom)
{
	int	*tab;

	tab = cpy_stack_to_tab(bottom);
	tab = bubble_sort(tab, stack_length(bottom));
	tab_to_stack(bottom, tab, stack_length(bottom));
}
