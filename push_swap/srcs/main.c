/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:27:27 by fbougama          #+#    #+#             */
/*   Updated: 2021/07/09 16:21:16 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{	
	t_stacks	*stacks;

	if (!check_arguments(ac - 1, &av[1]))
	{
		printf("Error\n");
		return (1);
	}
	if(!(stacks = initiate_stacks(ac - 1, &av[1])))
		return (-1);
	print_stack(stacks->a);
	// printf("\nb:\n");
	// printf("\ntaille : %ld\n", sizeof(t_list2 **));
	// printf("\ntaille : %ld\n", sizeof(t_list2 *));
	// print_stack(stacks->b);
	swap(stacks->a);
	// push_ab(stacks->a, stacks->b);
	// push_ab(stacks->a, stacks->b);
	// swap(stacks->b);

	printf("\nafter\n");
	print_stack(stacks->a);
	// printf("\nb:\n");
	// print_stack(stacks->b);
	return (0);
}
