/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:27:27 by fbougama          #+#    #+#             */
/*   Updated: 2021/08/13 16:16:07 by faysal           ###   ########.fr       */
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
	if (!(stacks = initiate_stacks(ac - 1, &av[1])))
		return (-1);
	return (0);
}
