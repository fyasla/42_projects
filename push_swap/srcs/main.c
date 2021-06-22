/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:27:27 by fbougama          #+#    #+#             */
/*   Updated: 2021/06/23 00:44:41 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{	
	int		*a;
	int		*b;
	int		i;
	t_list2	***stacks;

	i = 1;
	if (!check_arguments(ac - 1, &av[1]))
	{
		printf("Error\n");
		return (1);
	}
	if(!(stacks = initiate_stacks(ac - 1, &av[1])))
		return (-1);
	print_stack(*stacks);
	ft_lst2deltop(*stacks);
	print_stack(*stacks);
	return (0);
}
