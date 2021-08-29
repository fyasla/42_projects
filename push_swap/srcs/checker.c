/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 22:28:22 by faysal            #+#    #+#             */
/*   Updated: 2021/08/29 02:00:59 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	if (ac == 1)
		return (0);
	if (!check_arguments(ac - 1, &av[1]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stacks = initiate_stacks(ac - 1, &av[1]);
	if (!stacks)
		return (-1);
	if (instructions_parse(stacks) == -1)
	{
		ft_lst2clear(stacks->a);
		ft_lst2clear(stacks->b);
		free(stacks);
		return (-1);
	}
	if (is_ok(stacks))
		write(2, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	free_stacks(stacks);
	return (0);
}
