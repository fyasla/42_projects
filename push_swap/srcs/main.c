/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:27:27 by fbougama          #+#    #+#             */
/*   Updated: 2021/08/29 02:00:39 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{	
	t_stacks	*stacks;
	char		*inst_list;

	inst_list = malloc(sizeof(char));
	if (!inst_list)
		return (-1);
	ft_memset(inst_list, 0, 1);
	if (!check_arguments(ac - 1, &av[1]))
	{
		free(inst_list);
		write(2, "Error\n", 6);
		return (1);
	}
	stacks = initiate_stacks(ac - 1, &av[1]);
	if (!stacks)
		return (-1);
	stack_transfo(stacks->a);
	inst_list = sort(stacks, inst_list);
	write(1, inst_list, ft_strlen(inst_list));
	free(inst_list);
	free_stacks(stacks);
	return (0);
}
