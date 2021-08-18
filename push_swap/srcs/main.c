/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:27:27 by fbougama          #+#    #+#             */
/*   Updated: 2021/08/18 17:28:31 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{	
	t_stacks	*stacks;
	char		*inst_list;

	if (!(inst_list = malloc(sizeof(char))))
		return (-1);
	ft_memset(inst_list, 0, 1);
	if (!check_arguments(ac - 1, &av[1]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!(stacks = initiate_stacks(ac - 1, &av[1])))
		return (-1);
	inst_list = sort(stacks, inst_list);
	printf("%s", inst_list);
	return (0);
}
