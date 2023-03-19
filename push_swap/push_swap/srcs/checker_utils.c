/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:24:16 by faysal            #+#    #+#             */
/*   Updated: 2021/08/29 20:32:28 by faysal           ###   ########.fr       */
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

int	check_args_error(char *inst_list, int ac, char **args, int mode)
{
	if (mode == 1)
		free(inst_list);
	write(2, "Error\n", 6);
	free_args(args, ac);
	return (1);
}

void	set_args(char ***args, int *n, char **av, int ac)
{
	*n = ac - 1;
	*args = &av[1];
	if (ac == 2)
	{
		*n = 0;
		*args = ft_split(av[1], ' ');
		while ((*args)[*n] != NULL)
			(*n)++;
	}
}
