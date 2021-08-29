/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:27:27 by fbougama          #+#    #+#             */
/*   Updated: 2021/08/29 20:35:33 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{	
	t_stacks	*stacks;
	char		*inst_list;
	char		**args;
	int			n;

	inst_list = malloc(sizeof(char));
	if (!inst_list)
		return (-1);
	set_args(&args, &n, av, ac);
	ft_memset(inst_list, 0, 1);
	if (!check_arguments(n, args))
		return (check_args_error(inst_list, ac, args, 1));
	stacks = initiate_stacks(n, args);
	if (!stacks)
		return (-1);
	stack_transfo(stacks->a);
	inst_list = sort(stacks, inst_list);
	write(1, inst_list, ft_strlen(inst_list));
	free(inst_list);
	free_stacks(stacks);
	free_args(args, ac);
	return (0);
}
