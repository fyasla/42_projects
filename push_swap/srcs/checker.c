/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 22:28:22 by faysal            #+#    #+#             */
/*   Updated: 2021/08/29 20:33:41 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	int			n;
	char		**args;

	if (ac == 1)
		return (0);
	set_args(&args, &n, av, ac);
	if (!check_arguments(n, args))
		return (check_args_error("", ac, args, 2));
	stacks = initiate_stacks(n, args);
	if (!stacks)
		return (-1);
	if (instructions_parse(stacks) == -1)
	{
		free_args(args, ac);
		free_stacks(stacks);
		return (-1);
	}
	if (is_ok(stacks))
		write(2, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	free_stacks(stacks);
	free_args(args, ac);
	return (0);
}
