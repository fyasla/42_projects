/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:27:27 by fbougama          #+#    #+#             */
/*   Updated: 2021/06/24 02:39:10 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{	
	t_list2	***stacks;

	if (!check_arguments(ac - 1, &av[1]))
	{
		printf("Error\n");
		return (1);
	}
	if(!(stacks = initiate_stacks(ac - 1, &av[1])))
		return (-1);
	print_stack(*stacks);
	print_stack(*(stacks + sizeof(t_list2 **)));
	push_ab(*stacks, *(stacks + sizeof(t_list2 **)));

	printf("\nafter\n");
	print_stack(*stacks);
	print_stack(*(stacks + sizeof(t_list2 **)));
	return (0);
}
